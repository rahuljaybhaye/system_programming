/* Program : To check same variables in parent process & child process
*********virtual address of variables are same in both but actual memory is different, if change varible data in parent that will not reflect in child process and vice versa
**** If data change in child process then copy on write technique applied,
*/
#include<stdio.h>
#include<unistd.h>		// fork()

main()
{
	pid_t pid,ppid;
	int x = 10;

	int ret;

	printf("Hello user\n");
	printf("start");

	ret = fork();
	printf("ret->%u\n",ret);
	if(ret>0)
	{
		sleep(2);
//		for(x=1;x<10000;x++)
//		printf("1"); 
		x = 30;
		printf("Parent Process (x)-> %d,(addr):%p\n",x,&x);
		printf("Parent Process\n");
		printf("parent: pid->%u,ppid->%u\n",getpid(),getppid());
		printf("Parent is terminated\n");

	}
	else
	{
		sleep(3);
		printf("Child Process\n");
		printf("Child Process (x)-> %d,(addr):%p\n",x,&x);
		printf("child : pid->%u,ppid->%u\n",getpid(),getppid());
		printf("Child is terminated\n");

	}
	printf("End");
}

