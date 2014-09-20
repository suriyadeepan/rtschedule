/* includes */
#include "vxWorks.h"
#include "taskLib.h"
#include "kernelLib.h"
#include "sysLib.h"
#include "logLib.h"
#include "delayLib.h"


/* interface */
void dummytask(int i);
int precision(void);
void schedular(void);
int main(void);


/* globals */

#define NUMTASKS 3 

/* unit of time used : 100 milliseconds */
#define TIMEUNIT 100000

/* to make active delay in dummytask slower than a inactive blocked taskDelay  schedulare */
/* this value has to be manually set */
#define CALIBRATE 1.00

/* note : schedular has priority 100 if started with "sp sched" 
          -> priority of schedular has to be higher than all other tasks */



/* tasks settings */
int  exectime[NUMTASKS] = { 2, 6 , 5};
int  period[NUMTASKS] = { 10 , 20 , 10 };
int  deadline[NUMTASKS] = { 10 , 20 , 10 };
int  priority[NUMTASKS] = { 102 , 103 , 101 };



/* global schedular parameters shared with dummytask */
int  timer[NUMTASKS]; /* each tasks its own timer */
/* when task starts exectuting active is set */
/* when more tasks are active than one has preempted the other */
int  active[NUMTASKS];
/* to check if a task is done before its deadline is reached */ 
int  done[NUMTASKS];
int  task[NUMTASKS];
/* time of schedular : global time */
int  globaltime,globaltick;
/* schedular keeps track of single running task (one cpu) */
int runningtask=-1; /* -1 means the idle task */








void schedular(void) /* schedular */
{

  /* microsecs per tick */ 
  int mpt = (1000 * 1000) / sysClkRateGet ();
  /* ticks in TIMEUNIT */
  int ticksinTIMEUNIT=TIMEUNIT/mpt; 


  /* helper variables */
  int i,stop;
  char message[100]; 
  char tmpstring[10];
 
  logMsg("\n\nstart initialization \n\n",0,0,0,0,0,0);
  /* initialize active waiting function */
  delayUsec (-1); /*very first call used for calibration */

  for (i=0 ;i<NUMTASKS ;i++ ){ 
    /* all tasks are initially not running (active) */
    active[i]=0;
    done[i]=0;
    /* set all task to end of periode, so that they are immediately started */
    timer[i]=0;
  }

  

  logMsg("initialization done \n\n",0,0,0,0,0,0);

  globaltime=0;
  globaltick=tickGet();

  /* turn off round robin */
  kernelTimeSlice(0); 
  
  /* turn on round robin */ 
  /* kernelTimeSlice(ticksinTIMEUNIT); */


  while ( 1 ) {


  /***********************************************************/
  /*  spawn new tasks                                        */
  /* ( and schedule a task : done by vxworks schedular )     */
  /***********************************************************/

    /* spawn new task at beginning of period */
    for (i=0 ;i<NUMTASKS ;i++ ) { 
      /* spawn task at begin each period */ 
      if (timer[i]==0) {
        /* we define : deadline <= period */
        /* spawn a new task */
        done[i]=0;
        sprintf(tmpstring,"task%i",i);
        logMsg("time %i.%i : task%i spawned\n",globaltime,precision(),i,0,0,0);
        if((task[i] = taskSpawn(tmpstring,priority[i],0x100,20000,(FUNCPTR)dummytask,i,
                                 0,0,0,0,0,0,0,0,0)) == ERROR) printf("taskSpawn %i failed\n",i);
      }
      
    }


    /* print status of tasks */ 
    sprintf(message,"time %i.%i : running task : %d , activity : ",globaltime,precision(),runningtask); 
    for (i=0 ;i<NUMTASKS ;i++ ){ 
       sprintf(tmpstring," task%i=%i ",i,active[i]);
       strcat(message,tmpstring);
    }
    strcat(message,"\n");
    logMsg(message,0,0,0,0,0,0);

     


  /***********************************************************/
  /*  let system run a schedule interval                     */
  /***********************************************************/

    /* delay schedule interval */ 
    taskDelay(ticksinTIMEUNIT);

    /* update timers */
    globaltime++; 
    globaltick=tickGet();
    for (i=0 ;i<NUMTASKS ;i++ ){ timer[i]++; }

  /***********************************************************/
  /*  CHECKS and RESETS                                      */ 
  /*         check deadlines                                 */
  /*         reset task timers in necessary                  */
  /*         check if done                                   */
  /***********************************************************/



    /* check deadline of tasks and spawn tasks at beginning of their period */
    for (i=0 ;i<NUMTASKS ;i++ ){ 
       
      /* check if deadline missed */
      if ((timer[i]==deadline[i]) && ( done[i] == 0 ) ) {
         /* active task should have been finished before deadline */
         logMsg("\n\ntime %i.%i : task %d missed deadline !!\n\n",globaltime,precision(),i,0,0,0);
         /* ok, we are done : stop the program */
         for (i=0 ;i<NUMTASKS ;i++ ) taskDelete(task[i]);
         return; 
      } 
    }

    /* reset task timer at end of period */  
    for (i=0 ;i<NUMTASKS ;i++ ) {
       /* reset timer at end of period */ 
       if (timer[i]==period[i]) timer[i]=0;
    }  


    /* check if done
    check to see if all task start at a new period at the same time,
    when this is true, we are back at the beginning so we can stop */
    stop=1;
    for (i=0 ;i<NUMTASKS ;i++ ){ 
      if ( timer[i] != 0 ) stop=0;
    }
    if (stop == 1 && globaltime != 0) {
      /* ok, we are done : stop the program */
      logMsg("\n\n time %i.%i : all tasks back at beginning of period \n\n\n",globaltime,precision(),0,0,0,0);
      for (i=0 ;i<NUMTASKS ;i++ ) taskDelete(task[i]);           
      return;
    }


  }
}


int precision(void) 
{
   int ticks,usecs,mpt;
   ticks=tickGet()-globaltick;
   mpt = (1000 * 1000) / sysClkRateGet (); /* microsecs per tick     */
   usecs=mpt*ticks;
   /* first decimal */
   return ((usecs*10)/TIMEUNIT);
} 

void dummytask(int i) 
{
    int j;
    active[i]=1;
    runningtask=i;

    logMsg("time %i.%i : task %i started with planned exectime %i  \n",globaltime,precision(),i,exectime[i],0,0);
    
    /* run task for TIMEUNIT * exectime
       IMPORTANT : delayUsec does not sleep the task, but does active processing for 1 micro second!! 
    */
    /*  for setting runningtask we split this in 100 pieces */
    for (  j =0; j< (100 * exectime[i]);j++ ) 
    { 
       /* active delay 1/100 TIMEUNIT, so that runningtask variable is set between calls
          to schedular */ 
       delayUsec((TIMEUNIT/100)*CALIBRATE);
       runningtask=i;
    } 
    logMsg("time %i.%i : task %i finished after exectime %i  \n",globaltime,precision(),i,exectime[i],0,0);
    runningtask=-1;
    active[i]=0;
    done[i]=1;
}


int main(void)
{
   int maintask;
   if((maintask = taskSpawn("sched",100,0x100,20000,(FUNCPTR)schedular,0,
            0,0,0,0,0,0,0,0,0)) == ERROR) printf("taskSpawn schedular failed\n");
}

