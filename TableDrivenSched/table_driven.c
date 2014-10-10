#include <vxWorks.h>
#include <logLib.h>
#include <taskLib.h>
#include <stdio.h>

// POSIX API includes
#include <time.h>
#include <signal.h>

// global timer variables
timer_t timerid;
struct sigevent event;

struct itimerspec itime;
struct sigaction act;
	
// scheduling points
float sched_time[20] = {0,1,2,3.8,4,6,8,9.8,10.8,12,13.8};
int num_sched_points = 12;
int task_sched[20] = {1,3,2,0,1,0,3,2,1,0,2,1};

// interrupt flag
int intr0 = 0;

void handler(int);
void init_timer();
void start_timer(float);

// tasks
void t1();
void t2();
void t3();


// ENTRY point
void main(){
	
	int i;

	printf("\n@ENTRY Point\n");
	
	init_timer();
	
	for(i=0;i< num_sched_points-1;i++){
		
		// set interrupt flag to 0
		//  when interrupt occurs => flag is set to 1
		intr0 = 0;
		// start timer and interrupt @ (sched_time[i+1] - sched_time[i]) seconds 
		start_timer(sched_time[i+1] - sched_time[i]);
		printf("\n@%.2f ",sched_time[i]);
		
		
		// select the current task and spawn it
		switch(task_sched[i]){
		
		case 1:
			taskSpawn("t1",99,0x100,100,(FUNCPTR)t1,0,0,0,0,0,0,0,0,0,0);	
			break;
			
		case 2:
			taskSpawn("t2",99,0x100,100,(FUNCPTR)t2,0,0,0,0,0,0,0,0,0,0);	
			break;
			
		case 3:
			taskSpawn("t3",99,0x100,100,(FUNCPTR)t3,0,0,0,0,0,0,0,0,0,0);	
			break;
			
			// Ideal time
			//  FIX => Schedule aperiodic tasks in the queue, here...
		case 0:
			printf("IDLE\n\n");
			break;
			
		}
		
		// wait for interrupt to occur
		while(intr0 == 0)
			taskDelay(1);

	}
		
}

/*
 *  INTERRUPT handler
 * 		- invoked when timer expires
 */
void handler(int signo){
	intr0 = 1;
}

// Initialize timer DS's
void init_timer(){

	event.sigev_value.sival_int = 0;
	event.sigev_notify = SIGEV_SIGNAL;
	event.sigev_signo = SIGALRM;
	
	
	act.sa_handler = handler;
	act.sa_flags = 0;
	
	if (sigaction(SIGALRM,&act,NULL) == ERROR)
		printf("error while calling sigaction\n");
	
	if(timer_create(CLOCK_REALTIME,&event,&timerid) == ERROR)
		printf("error in timer creation\n");
}


// Start Timer with time (secs) as param
void start_timer(float time_secs){
	
	int secs = (int)time_secs;
	double nsecs = (time_secs - secs) * 1000 * 1000 * 1000;
	
	itime.it_value.tv_sec = secs;
	itime.it_value.tv_nsec = nsecs;
	itime.it_interval.tv_sec = 0;
	itime.it_interval.tv_nsec = 0;
	
	while( timer_settime(timerid, 0, &itime, NULL)== ERROR){
		//printf("error while starting the timer\n");
		taskDelay(1);
		// if failed... reinit timer
		init_timer();
	}
	
}

void t1(){
	//printf("\n*** TASK #1 ***\n");
	logMsg("\n*** TASK #1 ***\n",0,0,0,0,0,0);
}

void t2(){
	//printf("\n*** TASK #2 ***\n");
	logMsg("\n*** TASK #2 ***\n",0,0,0,0,0,0);
}

void t3(){
	//printf("\n*** TASK #3 ***\n");
	logMsg("\n*** TASK #3 ***\n",0,0,0,0,0,0);
}

