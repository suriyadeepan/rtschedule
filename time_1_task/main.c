#include "vxWorks.h"  /* Always include this as the first thing in every program */
#include "timexLib.h"
#include "stdio.h"
#include "taskLib.h"

#define ITERATIONS 100

int printit(void);


void timing() /* Function to perform the timing */
{
	/* a pointer to the function "printit" */
	FUNCPTR function_ptr = printit; 
	/* Timing the "print" function */ 
	timex(function_ptr,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
}

int printit(void) /* Function being timed */
{
	int i;
	
	for(i=0; i < ITERATIONS; i++)  /* Printing the task id number and the increment variable "i" */
		printf("Hello, I am task %d and is i = %d\n",taskIdSelf(),i);
	
	return 0;
}
