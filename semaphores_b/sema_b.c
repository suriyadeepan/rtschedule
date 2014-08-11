#include "vxWorks.h"
#include "taskLib.h"
#include "semLib.h"
#include "stdio.h"

void taskOne(void);
void taskTwo(void);

/* globals */
#define ITER 10
SEM_ID semBinary;
int global = 0;


void main(void){

	int taskIdOne, taskIdTwo;

	/* create semaphore with semaphore available and queue tasks on FIFO basis */
	semBinary = semBCreate(SEM_Q_FIFO, SEM_FULL);

	/* Note 1: lock the semaphore for scheduling purposes */
	semTake(semBinary,WAIT_FOREVER);

	/* spawn the two tasks */
	taskIdOne = taskSpawn("t1",90,0x100,2000,(FUNCPTR)taskOne,0,0,0,0,0,0,0,0,0,0);
	taskIdTwo = taskSpawn("t2",90,0x100,2000,(FUNCPTR)taskTwo,0,0,0,0,0,0,0,0,0,0);
}



void taskOne(void)
{
	int i;
	for (i=0; i < ITER; i++){
		
		semTake(semBinary,WAIT_FOREVER); /* wait indefinitely for semaphore */
		printf("I am taskOne and global = %d......................\n", ++global);
		semGive(semBinary); /* give up semaphore */
	} 
}

void taskTwo(void)
{
	int i;
	semGive(semBinary); /* Note 2: give up semaphore(a scheduling fix) */
	
	for (i=0; i < ITER; i++){
	
		semTake(semBinary,WAIT_FOREVER); /* wait indefinitely for semaphore */
		printf("I am taskTwo and global = %d----------------------\n", --global);
		semGive(semBinary); /* give up semaphore */
	} 
}