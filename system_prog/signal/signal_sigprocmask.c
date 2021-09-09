/* combination of signal (change behaviour) and sigprocmask-> blocking signal*/
#include<unistd.h>
#include<stdio.h>
#include<signal.h>
#include<sys/types.h>

void mysignalhandler(int);

main()
{

	sigset_t mask;
	sigemptyset(&mask);
	sigaddset(&mask,1);
	sigprocmask(SIG_BLOCK,&mask,0);

	printf("start");	//signal behaviour default -> SIG_DFL
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
	printf("Fun-> mysignal handler %d",signo);
	sleep(1);
}
