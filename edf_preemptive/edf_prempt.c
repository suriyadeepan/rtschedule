#include "vxworks.h"
#include "logLib.h"
#include "taskLib.h"
#include "tickLIb.h"

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
	
	int exec = C[0];
	int cnt = 0, tickValue = -1;
	
	if(END_TIME != -1){
		logMsg("*** Task : T1 ***\n",0,0,0,0,0,0);
		while(cnt < (exec*time_slice)){
			
			int newTick = tickGet();
			
			if(newTick > tickValue){
				cnt++;
				tickValue = newTick; 
			}
			
		}// end of while
		
	}
	
	
}

void t2(){
	int exec = C[1];
	int cnt = 0, tickValue = -1;
	
	if(END_TIME != -1){
		logMsg("*** Task : T2 ***\n",0,0,0,0,0,0);
		while(cnt < (exec*time_slice)){
			
			int newTick = tickGet();
			
			if(newTick > tickValue){
				cnt++;
				tickValue = newTick; 
			}
			
		}// end of while
		
	}
	
}

void t3(){
	
	
	int exec = C[2];
	int cnt = 0, tickValue = -1;
	
	if(END_TIME != -1){
		logMsg("*** Task : T3 ***\n",0,0,0,0,0,0);
		while(cnt < (exec*time_slice)){
			
			int newTick = tickGet();
			
			if(newTick > tickValue){
				cnt++;
				tickValue = newTick; 
			}
			
		}// end of while
		
	}
	
}

void updateParams(int *rdl, int *ret, int t1, int tid_current){
	
	int i;
	for(i=0;i<N_TASKS;i++){
		rdl[i] -= t1;
		if(rdl[i] <= 0){
			rdl[i] = T[i];
			ret[i] = C[i];
		}
	}
	
	if(tid_current >=0)
		ret[tid_current] -= t1;
		
}

int findBestTask(int *rdl, int *ret,int current_id){
	
	// find the best task 
	//		=> task with smallest relative dealine
	int i;
	int min_val = 1000;
	int min_rdl_id = -1;
	
	
	//logMsg("\n",0,0,0,0,0,0);
	for(i=0;i<N_TASKS;i++){
		
		//logMsg("rdl[%d] : %d ret[%d] : %d\n",i,rdl[i],i,ret[i],0,0);
		
		if(min_val > rdl[i] && ret[i] > 0){
			min_val = rdl[i];
			min_rdl_id = i;
		}
	}
	
	if(current_id != -1 && rdl[current_id] == rdl[min_rdl_id] && ret[current_id] > 0)
		return current_id;
		
	return min_rdl_id;
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

int nextEvent(int t, int current){
	
	/* Execution time of current task
	 * 
	 */
	int exec = ret[current];
	
	/*
	 *  get a copy of rdl and ret
	 * 
	 */
	int i;
	int rd[5];
	int re[5];
	
	for(i=0;i<N_TASKS;i++){
		rd[i] = rdl[i];
		re[i] = ret[i];
	}
	
	/*
	 * find the next event => change in task id
	 */
	for(i=0;i<exec;i++){
		updateParams(rd,re,1,current);
		current = findBestTask(rd,re,current);
	}
	
	return i;
	
}

void edf_preempt_sched(){
	
	int i=0,t1,j=0;
	int tid_current = -1;
	
	// define a time slice
	
	// spawn all tasks
	spawnAll();
	
	
	while(i<END_TIME){

		for(j=0;j<N_TASKS;j++)
			logMsg("rdl[%d] : %d ret[%d] : %d\n",j,rdl[j],j,ret[j],0,0);
		
		// find the most valid task
		//  (i.e) least relative deadline
		tid_current = findBestTask(rdl,ret,tid_current);
		nextEvent(i,tid_current);
		
		t1 = nextEvent(i,tid_current);
		
		logMsg("iteration : %d tid : %d nextEvent : %d\n",i,tid_current,i+t1,0,0,0);
		
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
			taskDelay(t1*time_slice);
			spawnAll(); //--> BUG FIX 01
		}
		
		else
			logMsg("--> edf_sched : idle\n",0,0,0,0,0,0);
	
		// update parameters 
		//		: relative exec time => ret
		//		: relative deadline  => rdl
		updateParams(rdl,ret,t1,tid_current);
		//spawnAll(); --> BUG FIX 01
		
		i = i + t1;
		
	}
	
	END_TIME = -1;
	
}