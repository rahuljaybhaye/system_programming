/******* Program to check after fork()- file object of pcb same or diifferent ***********
 After fork() parent & child process have seprate pcb , file object seprate of same file
	when any process modifies data copy on write technique applied and then mem. segment differ from one unother
*/

#include<unistd.h>	//fork(),lseek(),read(),write()
#include<stdio.h>	//printf()
#include<sys/wait.h>
#include<fcntl.h>	//open()

int main()
{
	pid_t pid,ppid;

	int ret;
	int status;
	int a;
	int fd;
	char wbuf[] = "Founder";
	char rbuf[10];

	//opening file to check file object of two process same or different
	fd = open("3.txt",O_RDWR|O_CREAT,0644);

	if(fd > 0 )
	{
		printf("File open successfully, fd: %d\n",fd);
	}
	else
	{
		printf("file unable to open\n");
		exit(1);
	}

	// creating child process
	pid = fork();

	printf("after fork\n");

	if(pid>0)
	{
		printf("In parent process\n");

		ret = write(fd,wbuf,strlen(wbuf));
		//sleep(5);
		printf("parent:child pid %d\n",pid);
		//printf("getpid: %d\t,getppid: %d\n",getpid(),getppid());

	}
	else
	{
		printf("In child proces\n");
		//lseek(fd,0,SEEK_SET);
		ret = read(fd,rbuf,9);

		rbuf[ret] = '\0';
		printf("Read %d bytes from file is: %s",ret,rbuf);
		//a = 1/0 ;
		//for( ; ;);
		//sleep(2);
		printf("child: %d\n",pid);
		//printf("getpid: %d\t,getppid: %d\n",getpid(),getppid());
	}
}
