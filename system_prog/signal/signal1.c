/* Program to write singnal handler functionn

	typedef void (*sighandler_t)(int);
	sighandler_t signal(int signum, sighandler_t handler);
 */
#include<unistd.h>		//sleep()
#include<stdio.h>
#include<signal.h>		//signal()

void mysignalhandler(int);

main()
{
	printf("start");
	signal(1,mysignalhandler);	//changing behaviour of signal 1 which is present is signal disposition table
	while(1)
	{
	printf("main fun\n");
	sleep(1);
	}
}

void mysignalhandler(int signo)
{
	printf("Fun-> mysignal handler %d",signo);
	sleep(1);
}
