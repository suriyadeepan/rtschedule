#include "vxWorks.h"  /* Always include this as the first thing in every program */
#include "timexLib.h"
#include "stdio.h"
#include "taskLib.h"
#include "msgQLib.h"


/* function prototypes */
void taskOne(void);
void taskTwo(void);

/* defines */
#define MAX_MESSAGES 100
#define MAX_MESSAGE_LENGTH 50

/* globals */
MSG_Q_ID mesgQueueId;

void message(void) /* function to create the message queue and two tasks */
{
	int taskIdOne, taskIdTwo;

	/* create message queue */
	if ((mesgQueueId = msgQCreate(MAX_MESSAGES,MAX_MESSAGE_LENGTH,MSG_Q_FIFO))
			== NULL)
		printf("msgQCreate in failed\n");

	/* spawn the two tasks that will use the message queue */
	if ((taskIdOne = taskSpawn("t1", 90, 0x100, 2000, (FUNCPTR)taskOne, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0)) == ERROR)
		printf("taskSpawn taskOne failed\n");
	if ((taskIdTwo = taskSpawn("t2", 90, 0x100, 2000, (FUNCPTR)taskTwo, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0)) == ERROR)
		printf("taskSpawn taskTwo failed\n");
}

void taskOne(void) /* task that writes to the message queue */
{
	char message[] = "Received message from taskOne";
	char msgBuf[MAX_MESSAGE_LENGTH];

	/* send message */
	if ((msgQSend(mesgQueueId, message, MAX_MESSAGE_LENGTH, WAIT_FOREVER, 
	MSG_PRI_NORMAL)) == ERROR)
		printf("msgQSend in taskOne failed\n");
	
	/* receive message */
	if (msgQReceive(mesgQueueId, msgBuf, MAX_MESSAGE_LENGTH, WAIT_FOREVER)
			== ERROR)
		printf("msgQReceive in taskOne failed\n");
	else
		printf("%s\n", msgBuf);
	msgQDelete(mesgQueueId); /* delete message queue */	
	
}

void taskTwo(void) /* tasks that reads from the message queue */
{

	char message[] = "Received message from taskTwo";
	char msgBuf[MAX_MESSAGE_LENGTH];


	/* receive message */
	if (msgQReceive(mesgQueueId, msgBuf, MAX_MESSAGE_LENGTH, WAIT_FOREVER)
			== ERROR)
		printf("msgQReceive in taskTwo failed\n");
	else
		printf("%s\n", msgBuf);
	msgQDelete(mesgQueueId); /* delete message queue */	
	
	/* send message */
	if ((msgQSend(mesgQueueId, message, MAX_MESSAGE_LENGTH, WAIT_FOREVER, 
	MSG_PRI_NORMAL)) == ERROR)
		printf("Message Sending from 2 failed!!!");
	
	

}