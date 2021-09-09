/*  fork() system call - in parent process return child pid
		       -  in  child process return  zero
	getpid() & getppid() -> system calls for  process id and parent pid info of current process 
*/
#include<stdio.h>
#include<unistd.h>		// fork()
#include<stdlib.h>		//exit()

main()
{
	pid_t pid,ppid;
	int ret;
	printf("Hello");
	printf("start\n");

	ret = fork();
	printf("ret->%u\n",ret);
	if(ret>0)
	{
		printf("Parent Process\n");
		printf("pid->%u,ppid->%u\n",getpid(),getppid());
		printf("Parent is terminated\n");
		exit(0);
	}
	else
	{
		printf("Child Process\n");
		printf("pid->%u,ppid->%u\n",getpid(),getppid());
		printf("Child is terminated\n");
		exit(1);
	}
	printf("End\n");
}

