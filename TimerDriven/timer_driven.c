/* includes */
#include <vxWorks.h>
#include <time.h>
#include <stdio.h>
#include <taskLib.h>
#include <signal.h>

// global timer variables
timer_t timerid;
struct sigevent event;

struct itimerspec itime;
struct sigaction act;
	
	
void handler(int);
void init_timer();
void start_timer(int,int);

// ENTRY point
void main(){

	printf("main:hello\n");
	
	init_timer();
	start_timer(5,0);
	
	while(1)
		taskDelay(1);	
		
}

void handler(int signo)

{
	printf("timer has expired");
	
}

void init_timer(){

	event.sigev_value.sival_int = 0;
	event.sigev_notify = SIGEV_SIGNAL;
	event.sigev_signo = SIGALRM;
	
	
	act.sa_handler = handler;
	act.sa_flags = 0;
	
	if (sigaction(SIGALRM,&act,NULL) == ERROR)
		printf("error while calling sigaction\n");
	
	
	
	if(timer_create(CLOCK_REALTIME,&event,&timerid) == ERROR)
		printf("error in timer creation\n");
	
	
	
}

void start_timer(int secs, int ms){
	
	itime.it_value.tv_sec = secs;
	itime.it_value.tv_nsec = 0;
	itime.it_interval.tv_sec = 0;
	itime.it_interval.tv_nsec = 0;
	
	if( timer_settime(timerid, 0, &itime, NULL)== ERROR)
		printf("error while starting the timer\n");
	
}

	