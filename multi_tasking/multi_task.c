#include "vxWorks.h"
#include "timexLib.h"
#include "taskLib.h"
#include "stdio.h"

#define ITER 10

void print_task();

void main(){
	
	int taskId,i=0;
	
	for(;i<ITER;i++)
		taskId = taskSpawn("tprint_task",100,0x100,200,
				(FUNCPTR)print_task,i,0,0,0,0,0,0,0,0,0);
	
}
void print_task(void){
	printf("\nExecute print_task : %d",taskIdSelf());
}