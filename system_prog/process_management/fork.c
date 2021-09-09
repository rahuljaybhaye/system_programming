#include<stdio.h>
#include<unistd.h>		// fork()
#include<stdlib.h>		//exit()

main()
{
	pid_t pid,ppid;
	printf("start\t");

	pid = fork();
	printf("pid value->%d\n",pid);
	if(pid>0)
	{
		printf("Parent task executed\n");
		exit(0);
	}
	else
	{
		printf("Child task executed\n");
		exit(1);
	}
	printf("End");
}

