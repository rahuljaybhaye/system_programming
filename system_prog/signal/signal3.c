/* Program to check pause() and alarm()

*  int pause(void);
  pause()  causes the calling process (or thread) to sleep until a signal
  is delivered that either terminates the process or causes  the  invoca‐
  tion of a signal-catching function.

** unsigned int sleep(unsigned int seconds);

*** unsigned int alarm(unsigned int seconds);

*****  int raise(int sig);
		Used to send a signal to calling process itself like kill()

 */
#include<unistd.h>	// sleep(<sec>), pause()
#include<stdio.h>	// printf(), scanf()
#include<signal.h>	// signal(),raise()
void mysignalhandler(int);

main()
{
	int ret;
	printf("start\n");
	ret = signal(14,mysignalhandler);
	printf("ret= %d\n",ret);

	while(1)
	{
	printf("I am waiting for any one of 64 signals\n");
	//alarm -> before decremented to zero if any alarm() signal get then time modified, Thus in infinite while loop,if only alarm(),then it not genrate SIGALRM signal
	//alarm(5);	//not block,not context switch only decrement  seconds time when zero -> send SIGALRM signal to itself
	//pause();	//blocking call -> block until process Rx any signal outoff 64 signals

	//alarm signal bring process out of blocking state, thus every 3 sec process run 
	//alarm(3);
	sleep(20);
	raise(SIGSTOP);
	}
}

void mysignalhandler(int signo)
{
	printf("Fun-> mysignal handler %d \n",signo);
//	sleep(3);
}
