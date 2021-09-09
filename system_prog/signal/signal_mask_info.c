#include<signal.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
	sigset_t mask,oldmask;

	sigemptyset(&mask);
	sigaddset(&mask,14);

	sigprocmask(SIG_BLOCK,&mask,&oldmask);


	printf("oldmask:%x\n",oldmask);
	printf("curmask:%x\n",mask);




}

