/********************Zombie Process *******************************
**	A zombie process is a process whose execution is completed but it still has an entry in the process table. Zombie processes usually occur for child processes, as the parent process still needs to read its child’s exit status. Once this is done using the wait system call, the zombie process is eliminated from the process table. This is known as reaping the zombie process. 
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int status;
	printf("start\n");
	pid_t val = fork();
	if(val != 0)
	{
		printf("parent,started\n");
		sleep(30);			//blocking call - pcb moved from running queue to waiting queue till  sleep seconds terminated and execuation goes to child process
		printf("parent,waiting\n");
		int ret = wait(&status);
		printf("parent,terminatd ret : %d\n",ret);
		exit(0);
	}
	else
	{
		printf("child process started \n");
		printf("child : pid= %u \t ppid= %u\n",getpid(),getppid());

		printf("child process terminated \n");
		exit(1);
	}
}
