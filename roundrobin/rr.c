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
#define ITER1 100
#define ITER2 10
#define PRIORITY 101 
#define TIMESLICE sysClkRateGet()
#define LONG_TIME 1000000

void sched(void) /* function to create the three tasks */
{
int taskIdOne, taskIdTwo, taskIdThree;

if(kernelTimeSlice(2) == OK) /* turn round-robin on */
	printf("\n\n\n\n\t\t\tTIMESLICE = %f seconds\n\n\n", 2/60);

/* spawn the three tasks */
if((taskIdOne = taskSpawn("task1",PRIORITY,0x100,20000,(FUNCPTR)taskOne,0,0,0,0,0,0,0,
	0,0,0)) == ERROR)
	printf("taskSpawn taskOne failed\n");
if((taskIdTwo = taskSpawn("task2",PRIORITY,0x100,20000,(FUNCPTR)taskTwo,0,0,0,0,0,0,0,
	0,0,0)) == ERROR)
	printf("taskSpawn taskTwo failed\n");
if((taskIdThree = taskSpawn("task3",PRIORITY,0x100,20000,(FUNCPTR)taskThree,0,0,0,0,0,0,0,
	0,0,0)) == ERROR)
	printf("taskSpawn taskThree failed\n");

}

void taskOne(void) 
{
int i,j;
for (i=0; i < ITER1; i++)	
	{
	printf("\nT1\n");
	for (j=0; j < ITER2; j++)
		for (j=0; j < LONG_TIME; j++); /* allow time for context switch */	
	}


for (i=0; i < ITER1; i++)	
	{
	printf("\nT1\n");
	for (j=0; j < ITER2; j++)
		for (j=0; j < LONG_TIME; j++); /* allow time for context switch */	
	}

for (i=0; i < ITER1; i++)	
	{
	printf("\nT1\n");
	for (j=0; j < ITER2; j++)
		for (j=0; j < LONG_TIME; j++); /* allow time for context switch */	
	}

for (i=0; i < ITER1; i++)	
	{
	printf("\nT1\n");
	for (j=0; j < ITER2; j++)
		for (j=0; j < LONG_TIME; j++); /* allow time for context switch */	
	}
printf("\nEnd of T1\n");
}

void taskTwo(void) 
{
int i,j;
for (i=0; i < ITER1; i++)
	{
	printf("\nT2\n");
	for (j=0; j < ITER2; j++)
		for (j=0; j < LONG_TIME; j++); /* allow time for context switch */	
	}

for (i=0; i < ITER1; i++)
	{
	printf("\nT2\n");
	for (j=0; j < ITER2; j++)
		for (j=0; j < LONG_TIME; j++); /* allow time for context switch */	
	}



for (i=0; i < ITER1; i++)
	{
	printf("\nT2\n");
	for (j=0; j < ITER2; j++)
		for (j=0; j < LONG_TIME; j++); /* allow time for context switch */	
	}



for (i=0; i < ITER1; i++)
	{
	printf("\nT2\n");
	for (j=0; j < ITER2; j++)
		for (j=0; j < LONG_TIME; j++); /* allow time for context switch */	
	}



printf("\nEnd of T2\n");
}

void taskThree(void) 
{
int i,j;
for (i=0; i < ITER1; i++)
	{ 
	printf("\nT3\n");
	for (j=0; j < ITER2; j++)
		for (j=0; j < LONG_TIME; j++); /* allow time for context switch */	
	}

for (i=0; i < ITER1; i++)
	{ 
	printf("\nT3\n");
	for (j=0; j < ITER2; j++)
		for (j=0; j < LONG_TIME; j++); /* allow time for context switch */	
	}

for (i=0; i < ITER1; i++)
	{ 
	printf("\nT3\n");
	for (j=0; j < ITER2; j++)
		for (j=0; j < LONG_TIME; j++); /* allow time for context switch */	
	}


for (i=0; i < ITER1; i++)
	{ 
	printf("\nT3\n");
	for (j=0; j < ITER2; j++)
		for (j=0; j < LONG_TIME; j++); /* allow time for context switch */	
	}

for (i=0; i < ITER1; i++)
	{ 
	printf("\nT3\n");
	for (j=0; j < ITER2; j++)
		for (j=0; j < LONG_TIME; j++); /* allow time for context switch */	
	}



printf("\nEnd of T3\n");
}
