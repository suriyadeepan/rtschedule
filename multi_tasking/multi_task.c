#include "vxWorks.h"
#include "timexLib.h"
#include "taskLib.h"
#include "stdio.h"

#define ITER 15

void print_task();

void main(){
	
	int taskId,i=1;
	
	for(;i<ITER;i++)
		taskId = taskSpawn("tprint_task",i*50,0x100,200,
				(FUNCPTR)print_task,i,0,0,0,0,0,0,0,0,0);
	
}
void print_task(void){
	printf("\nTID : %d",taskIdSelf());
}