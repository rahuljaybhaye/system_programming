/*
* Program to wait parent till child termination by using wait() sys. call
* To get information of child termination by  WIFEXITED() or WIFSIGNALED() macro
* To get exit status value or signal by WEXITSTATUS() or WTERMSIG() macro


*/

#include<stdio.h>
#include<sys/wait.h>		// wait()
//#include<sys/types.h>		//wait()
#include<unistd.h>		//fork()
#include<stdlib.h>		//exit()

int main()
{
	int i = 1;
	int val;
	int *ptr = NULL;
	int num;
	pid_t pid;
	int status;		//status variable
	pid = fork();
	if(pid !=0 )
	{
		printf("parent process is going under blocking state\n");
		printf("parent, fork return:%d\n",pid);
		num = wait(&status);			//pid_t wait(int *statloc)
		printf("return wait: %d\n",num);

		if(WIFEXITED(status))						//True if child process terminated normally
			printf("if-parent: %d\n",WEXITSTATUS(status));		//WEXITSTATUS()  macro given value of exit fun
		else
			printf("else-parent: %d\n",WEXITSTATUS(status));

		if(WIFSIGNALED(status))						//True if child process terminated abnormally( By receiving a signal)
			printf("sig-if-parent: %d\n",WTERMSIG(status));		//WTERMSIG() Macro given value of signal due to which process terminated

		else
			printf("sig-else-parent: %d\n",WTERMSIG(status));

		printf("Parent is terminated \n");
	}
	else
	{
		printf("new child process is created \n");
		*ptr = 20;						//child process :terminated due to exception and send signal no 11 i.e. SIGSEGV 
	//	printf("%d\n",*ptr);
//		val = 1/0;							//child process :terminated due to exception and send signal no 8 i.e. SIGFPE (floating point error)
		while(i)
			printf("%d\t",i++);
		printf("child process is terminated...\n");
		exit(100);
	}
}
