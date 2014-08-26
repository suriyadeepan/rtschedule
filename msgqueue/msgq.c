/* includes */
#include "vxWorks.h"
#include "msgQLib.h"
#include "taskLib.h"
#include "stdio.h"

/* function prototypes */
void taskOne(void);
void taskTwo(void);

/* defines */
#define MAX_MESSAGES 100
#define MAX_MESSAGE_LENGTH 50

/* globals */
MSG_Q_ID msgQ1;
MSG_Q_ID msgQ2;

void message(void) /* function to create the message queue and two tasks */
{
	int taskIdOne, taskIdTwo;
	
	/* create 2 message queues for 2way */
	if ((msgQ1 = msgQCreate(MAX_MESSAGES,MAX_MESSAGE_LENGTH,MSG_Q_FIFO))
			== NULL)
		printf("msgQCreate in failed\n");
	
	if ((msgQ2 = msgQCreate(MAX_MESSAGES,MAX_MESSAGE_LENGTH,MSG_Q_FIFO))
			== NULL)
		printf("msgQCreate in failed\n");
		
	
	/* spawn the two tasks that will use the message queue */
	if((taskIdOne = taskSpawn("t1",90,0x100,2000,(FUNCPTR)taskOne,0,0,0,0,0,0,0,
			0,0,0)) == ERROR)
		printf("taskSpawn taskOne failed\n");
	if((taskIdTwo = taskSpawn("t2",90,0x100,2000,(FUNCPTR)taskTwo,0,0,0,0,0,0,0,
			0,0,0)) == ERROR)
		printf("taskSpawn taskTwo failed\n");
}


void taskOne(void) /* task that writes to the message queue */
{
	char message[] = "from t1 to t2";
	char msgBuf[MAX_MESSAGE_LENGTH];
	
	/* send message to queue 1*/
	if((msgQSend(msgQ1,message,MAX_MESSAGE_LENGTH, WAIT_FOREVER, 
			MSG_PRI_NORMAL)) == ERROR)
		printf("\nmsgQSend in taskOne failed\n");
	
	/* wait for msg on queue 2 */
	if(msgQReceive(msgQ2,msgBuf,MAX_MESSAGE_LENGTH, WAIT_FOREVER) 
			== ERROR)
		printf("\nmsgQReceive in T1 failed\n");	
	else
		printf("\nT1 : %s\n",msgBuf); 
	
	
	msgQDelete(msgQ1); /* delete the message queues */	
	msgQDelete(msgQ2); /* delete the message queues */	
		
	
}

void taskTwo(void) /* tasks that reads from the message queue */
{
	char msgBuf[MAX_MESSAGE_LENGTH];
	char message[] = "from t2 to t1";
	char message1[] = "msg2 from t2 to t1";
	
	/* receive message from queue 1*/
	if(msgQReceive(msgQ1,msgBuf,MAX_MESSAGE_LENGTH, WAIT_FOREVER) 
			== ERROR)
		printf("\nmsgQReceive in taskTwo failed\n");	
	else
		printf("\nT2 : %s\n",msgBuf); 
	
	/* send message to queue 2*/
	if((msgQSend(msgQ2,message,MAX_MESSAGE_LENGTH, WAIT_FOREVER, 
			MSG_PRI_NORMAL)) == ERROR)
		printf("\nmsgQSend in T2 failed\n");
	
}


