/* Program to check SIG_IGN behaviour */
#include<unistd.h>
#include<stdio.h>
#include<signal.h>
#include<sys/types.h>

void mysignalhandler(int);


main()
{

	printf("start\n");	//signal behaviour default -> SIG_DFL
	signal(1,mysignalhandler);
	//signal(44,SIG_IGN);


	while(1)
	{
	printf("main fun\n");
	sleep(1);
	}
}

void mysignalhandler(int signo)
{
	printf("Fun-> mysignal handler %d\n",signo);
	sleep(1);
}
