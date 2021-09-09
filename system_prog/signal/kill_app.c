/*
	 #include <sys/types.h>
       #include <signal.h>

       int kill(pid_t pid, int sig);
*/

#include<sys/types.h>
#include<signal.h>
#include<stdio.h>

int main()
{
	int ret;
	pid_t pid;
	printf("Enter the pid of proces\n");
	scanf("%u",&pid);
	ret = kill(pid,9);
//	ret = kill(pid,SIGKILL);
	printf("process %d killed,ret:%d",pid,ret);
}

