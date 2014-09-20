#include "vxworks.h"
#include "logLib.h"
#include "taskLib.h"
#include "stdio.h"

// #input params
int C[ ] = {10,3,10};
int T[ ] = {33,28,29};
int A[ ] = {0,4,5};

int ret[ ] = {10,3,10};int slack[ ] = {23,25,19};


// #tasks
int N_TASKS = 3;

// end time of simulation
int END_TIME = 25;

// array of tids
int tid[3];


void t1(){
	
	if(END_TIME != -1)
		logMsg("*** Task : T1 ***\n",0,0,0,0,0,0);
}

void t2(){
	
	if(END_TIME != -1)
		logMsg("*** Task : T2 ***\n",0,0,0,0,0,0);
}

void t3(){
	
	if(END_TIME != -1)
		logMsg("*** Task : T3 ***\n",0,0,0,0,0,0);
}

void updateParams(int tid_current, int t){
	
	int i;
	
	if(tid_current >=0 )
		if(ret[tid_current] > 0)
			ret[tid_current]--;
	
	for(i=0;i<N_TASKS;i++)
		slack[i] = T[i] - t - 1 - ret[i];
}

int findBestTask(int t){
	
	// find the best task 
	//		=> task with the smallest slack
	int i;
	int min_val = 1000;
	int min_slack_id = -1;
	
	for(i=0;i<N_TASKS;i++){
		
		if(min_val > slack[i] && ret[i] > 0 && A[i] <= t){
			min_val = slack[i];
			min_slack_id = i;
		}
	}
		
	return min_slack_id;
}

void suspendAll(){
	
	int i;
	for(i=0;i<N_TASKS;i++)
		taskSuspend(tid[i]);
}

void spawnAll(){
	
	if( taskIdVerify(tid[0]) == ERROR )
		tid[0] = taskSpawn("t1",101,0x100,1000,(FUNCPTR)t1,0,0,0,0,0,0,0,0,0,0);
	
	if( taskIdVerify(tid[1]) == ERROR )
		tid[1] = taskSpawn("t2",101,0x100,1000,(FUNCPTR)t2,0,0,0,0,0,0,0,0,0,0);
	
	if( taskIdVerify(tid[2]) == ERROR )
		tid[2] = taskSpawn("t3",101,0x100,1000,(FUNCPTR)t3,0,0,0,0,0,0,0,0,0,0);
}

void llf_sched(){
	
	int i;
	
	// Assign Time Slice in #ticks
	// 	[ 60 ticks ~= 1 second ]	int time_slice = 30;
	
	// spawn all tasks
	spawnAll();
	
	
	for(i=0;i<END_TIME;i++){
		
		// find the most valid task
		//  (i.e) least slack
		int tid_current = findBestTask(i);
		logMsg("iteration : %d tid : %d\n",i,tid_current,0,0,0,0);
		
		// * If a task is selected
		if(tid_current >= 0){
			// ** run selected task **
			//	putting current (high-priority)task in delay
			//		will switch context to already spawned task
			//			that is not in suspend state
			// 1] suspend all the tasks
			suspendAll();
			// 2] resume the selected task
			taskResume(tid[tid_current]);
			// 3] put current task in wait
			taskDelay(30);
			
			spawnAll(); //--> BUG FIX 01
		}
		
		else
			logMsg("--> llf_sched : idle\n",0,0,0,0,0,0);
	
		// update parameters 
		//		: relative exec time => ret
		//		: relative deadline  => rdl
		updateParams(tid_current,i);
		//spawnAll(); --> BUG FIX 01
		
	}
	
	END_TIME = -1;
	
}
