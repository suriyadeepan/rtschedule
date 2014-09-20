#include "vxworks.h"
#include "logLib.h"
#include "taskLib.h"
#include "stdio.h"

// #input params
int C[ ] = {1,2,4};
int T[ ] = {8,5,10};

int ret[ ] = {1,2,4};
int rdl[ ] = {8,5,10};

// #tasks
int N_TASKS = 3;

// end time of simulation
int END_TIME = 30;

// array of tids
int tid[3];

// Assign Time Slice in #ticks
int time_slice = 60; // ~= 1 second

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

void updateParams(int tid_current){
	
	int i;
	for(i=0;i<N_TASKS;i++){
		rdl[i]--;
		if(rdl[i] == 0){
			rdl[i] = T[i];
			ret[i] = C[i];
		}
	}
	
	if(tid_current >=0)
		ret[tid_current]--;
		
}

int findBestTask(){
	
	// find the best task 
	//		=> task with smallest relative dealine
	int i;
	int min_val = 1000;
	int min_rdl_id = -1;
	
	for(i=0;i<N_TASKS;i++){
		
		if(min_val > rdl[i] && ret[i] > 0){
			min_val = rdl[i];
			min_rdl_id = i;
		}
	}
		
	return min_rdl_id;
}

void suspendAll(){
	
	int i;
	for(i=0;i<N_TASKS;i++)
		taskSuspend(tid[i]);
}

void spawnAll(){
	
	if( taskIdVerify(tid[2]) == ERROR )
		tid[0] = taskSpawn("t1",101,0x100,1000,(FUNCPTR)t1,0,0,0,0,0,0,0,0,0,0);
	
	if( taskIdVerify(tid[2]) == ERROR )
		tid[1] = taskSpawn("t2",101,0x100,1000,(FUNCPTR)t2,0,0,0,0,0,0,0,0,0,0);
	
	if( taskIdVerify(tid[2]) == ERROR )
		tid[2] = taskSpawn("t3",101,0x100,1000,(FUNCPTR)t3,0,0,0,0,0,0,0,0,0,0);
}

void edf_sched(){
	
	int i;
	
	// define a time slice
	
	// spawn all tasks
	spawnAll();
	
	
	for(i=0;i<END_TIME;i++){
		
		// find the most valid task
		//  (i.e) least relative deadline
		int tid_current = findBestTask();
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
			taskDelay(time_slice);
			spawnAll(); //--> BUG FIX 01
		}
		
		else
			logMsg("--> edf_sched : idle\n",0,0,0,0,0,0);
	
		// update parameters 
		//		: relative exec time => ret
		//		: relative deadline  => rdl
		updateParams(tid_current);
		//spawnAll(); --> BUG FIX 01
		
	}
	
	END_TIME = -1;
	
}
