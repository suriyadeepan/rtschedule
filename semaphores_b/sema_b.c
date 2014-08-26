/* includes */
#include "vxWorks.h"
#include "taskLib.h"
#include "semLib.h"
#include "stdio.h"

/* function prototypes */
void taskOne(void);
void taskTwo(void);
void taskThree(void);

/* globals */
#define ITER 10
SEM_ID semBinary;
int global = 0;
int var = 0;

void binary(void)
{
int taskIdOne, taskIdTwo, taskIdThree;

/* create semaphore with semaphore available and queue tasks on FIFO basis */
semBinary = semBCreate(SEM_Q_FIFO, SEM_FULL);

/* Note 1: lock the semaphore for scheduling purposes */
semTake(semBinary,WAIT_FOREVER);

//var = 1;
global = 1;

/* spawn the two tasks */
taskIdOne = taskSpawn("t1",90,0x100,2000,(FUNCPTR)taskOne,0,0,0,0,0,0,0,0,0,0);
taskIdTwo = taskSpawn("t2",90,0x100,2000,(FUNCPTR)taskTwo,0,0,0,0,0,0,0,0,0,0);
taskIdThree = taskSpawn("t3",90,0x100,2000,(FUNCPTR)taskThree,0,0,0,0,0,0,0,0,0,0);
}


void taskOne(void)
{
int i;
for (i=0; i < ITER; i++)
	{
	semTake(semBinary,WAIT_FOREVER); /* wait indefinitely for semaphore */
	if(global == 1){
		var = i;
		global = 2;
		printf("\nin task 1 : var = %d",var);
	}
	semGive(semBinary); /* give up semaphore */
	} 
}

void taskTwo(void)
{
int i;
semGive(semBinary); /* Note 2: give up semaphore(a scheduling fix) */
for (i=0; i < ITER; i++)
	{
	semTake(semBinary,WAIT_FOREVER); /* wait indefinitely for semaphore */
	if(global == 2){
		printf("\nin task 2 : var = %d",var/2);
		global = 3;
	}
	semGive(semBinary); /* give up semaphore */
	} 
}


void taskThree(void)
{
int i;
semGive(semBinary); /* Note 2: give up semaphore(a scheduling fix) */
for (i=0; i < ITER; i++)
	{
	semTake(semBinary,WAIT_FOREVER); /* wait indefinitely for semaphore */
	if(global == 3){
		printf("\nin task 3 : var = %d",var*2);
		global = 1;
	}
	semGive(semBinary); /* give up semaphore */
	} 
}
