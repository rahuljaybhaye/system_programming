/*
 int execlp(const char *file, const char *arg, ... /* (char  *) NULL /);

*   The  exec() family of functions replaces the current process image with a
       new process image

*/

#include<unistd.h>		//execlp(), fork()
#include<stdio.h>

int main()
{
	pid_t pid;
	int stat,ret;
	pid = fork();
	if(pid != 0)
	{
		printf("parent process is under execuation pid: %u \n",getpid());
		ret = wait(&stat);
		exit(0);
	}
	else
	{
		printf("./a.out(child process):pid %u\n",getpid());
		sleep(5);
//		execlp("ps","ps","-ef",0);
		execlp("ps","ps","ax",0);
		printf("my process terminated\n");
		exit(10);
	}
}
