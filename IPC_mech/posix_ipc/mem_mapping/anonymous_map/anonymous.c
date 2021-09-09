/************************************************************
*
 Posix IPC mechanisum - use only library call
 System V IPC mechanisum - use only system call


 If anonymous mapping  is not supported by your os then alternate method

	- Create memory which is not mapped to any file
	- Used to share data between parent and child process

*******************************************************/

#include<sys/mman.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/wait.h>
main()
{
	int pid,fd;
	int stat;
	//char *mem;
	int *addr ;

	*addr = 20;
	printf("address :- %p",addr);
	#ifdef USE_MAP_ANON

	printf("Anonymous mapping supported")
	addr = mmap(NULL,sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);

	#else
	//alternate method - access null file

	fd = open("/dev/zero",O_RDWR);
	printf("fd of zero file :%d\n",fd);
	addr = mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	close(fd);
	printf("address of physical fram :- %p\n",addr);
	#endif

	printf("parent process\n");

	pid = fork();
	printf("%d\n",pid);
	if(pid == 0)
	{
		printf("pid of fork:- %d\n",pid);
		printf("child process\n");
		*addr = 10;
		exit(1);
	}

	wait(&stat);
	printf("output - %d\n",*addr);
	printf("end");

}

