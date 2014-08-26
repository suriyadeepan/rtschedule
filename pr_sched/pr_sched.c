/* includes */
#include "vxWorks.h"
#include "taskLib.h"
#include "kernelLib.h"
#include "sysLib.h"
#include "logLib.h"
#include "stdio.h"

/* function prototypes */
void taskOne(void);
void taskTwo(void);
void taskThree(void);

/* globals */
#define ITER1 2
#define ITER2 1
#define LONG_TIME 1000000
#define HIGH 100 /* high priority */
#define MID 101 /* mdeium priority */
#define LOW 102 /* low priority */

void sched(void) /* function to create the two tasks */
{
int taskIdOne, taskIdTwo, taskIdThree;

printf("\n\n\n\n\n");
/* spawn the three tasks */
if((taskIdOne = taskSpawn("task2",LOW,0x100,20000,(FUNCPTR)taskOne,0,0,0,0,0,0,0,
	0,0,0)) == ERROR)
	printf("taskSpawn taskOne failed\n");
if((taskIdTwo = taskSpawn("task2",MID,0x100,20000,(FUNCPTR)taskTwo,0,0,0,0,0,0,0,
	0,0,0)) == ERROR)
	printf("taskSpawn taskTwo failed\n");
if((taskIdThree = taskSpawn("task3",HIGH,0x100,20000,(FUNCPTR)taskThree,0,0,0,0,0,0,0,
	0,0,0)) == ERROR)
	printf("taskSpawn taskThree failed\n");

}

void taskOne(void) 
{
int i,j;
printf("in task 1\n");
for (i=0; i < ITER1; i++)
	{
	for (j=0; j < ITER2; j++);
		//logMsg("\n",0,0,0,0,0,0);
		for (j=0; j < LONG_TIME; j++);	
	}
printf("\nend of task 1");
}

void taskTwo(void) 
{
int i,j;
printf("in task 2\n");
for (i=0; i < ITER1; i++)
	{
	for (j=0; j < ITER2; j++);
		//logMsg("\n",0,0,0,0,0,0);
		for (j=0; j < LONG_TIME; j++);
	}
printf("\nend of task 2");
}

void taskThree(void) 
{
int i,j;
printf("in task 3\n");
for (i=0; i < ITER1; i++)
	{ 
	for (j=0; j < ITER2; j++);
		//logMsg("\n",0,0,0,0,0,0);
		for (j=0; j < LONG_TIME; j++);
	}
printf("\nend of task 3");
}