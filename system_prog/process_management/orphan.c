/********************Orphan Process *******************************
** The process whose parent process terminated and after that child process accepted by init process thus child process called as orphan process
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int *status;
	printf("start\n");
	pid_t val = fork();
	if(val != 0)
	{
		printf("parent,started\n");
		sleep(10);			//blocking call - pcb moved from running queue to waiting queue till  sleep seconds terminated and execuation goes to child process
		printf("parent,terminatd\n");
		exit(0);
	}
	else
	{
		printf("child process started \n");
		printf("child : pid= %u \t ppid= %u\n",getpid(),getppid());
		sleep(30);
		printf("child : pid= %u \t ppid= %u\n",getpid(),getppid());
		printf("child process terminated \n");
		exit(1);
	}
}
