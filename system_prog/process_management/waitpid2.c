#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int pid,val,i ;
	int status;
	pid = fork();					//child process created
	if(pid!= 0)
	{
		printf("parent process: %d\n",getpid());
		printf("parent: child pid %d\n",pid);
		sleep(1);
		printf("parent, out of blocking\n");
		pid = waitpid(pid,&status,WNOHANG); //WNOHANG //WCONTINUED			//wait til <pid> child process termination 

		printf("parent, waitpid return: %d\n",pid);
		printf("parent,wexitstatus : %d\n",WEXITSTATUS(status));
		exit(0);
	}

	else
	{
		printf("child process: %d\n",getpid());					//execute after fork() when parent block here
		for(i=1;printf("%d",i),i<10000000;i++);


		exit(2);
	}
}

