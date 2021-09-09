#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int pid,val;
	int status;
	pid = fork();					//child process created
	if(pid!= 0)
	{
		printf("parent process: %d\n",getpid());
		printf("parent: child pid %d\n",pid);
		pid = waitpid(pid,&status,WCONTINUED); //WNOHANG //WCONTINUED			//wait til <pid> child process termination 

		printf("parent, waitpid return: %d\n",pid);
		printf("parent,wexitstatus : %d\n",WEXITSTATUS(status));
		exit(0);
	}

	else
	{
		printf("child process: %d\n",getpid());					//execute after fork() when parent block here
		val = fork();								//created another child prcess
		printf("child, val:%d\n",val);
		printf("stoping process\n");
		kill(val,19);				//sending stop signal to val process
		if(val == 0)
		{



			printf("subchild, val = %d,pid=%d\n",val,getpid());
			sleep(6);
		}
		else
		{
			printf("in Subchild-Parent process\n");
			pid= waitpid(val,&status,WNOHANG);				// wait till val(pid) child process terminated but here due to WNOHANG if process is not available then it returns zero(not block) 

//			pid= waitpid(val,&status,0);//WCONTINUED			// wait till val(pid) child process terminated  


			printf("subchild-parent process,waitpid return :%d\n",pid);
			printf("subchild-parent process,wexitstatus: %d\n",WEXITSTATUS(status));
			 sleep(3);
			exit(3);
		}
		exit(2);
	}
}

