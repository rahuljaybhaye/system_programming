/*	****** For pipe() program************8
	The fork() system call allows one process, the parent, to create a new process, the child. This is done by making the new child process an (almost) exact 
dupli-cate of the parent: the child obtains copies of the parent’s stack, data, heap,and text segments

	When a fork() is performed, the child receives duplicates of all of the parent’s file descriptors. These duplicates are made in the manner of dup(), which 
means that corresponding descriptors in the parent and the child refer to the same open file description. The open file description contains the current

*/

#include<unistd.h>	//fork()
#include<string.h>	//strcpy()
#include<stdio.h>	//printf()
#include<fcntl.h>
int main()
{
	pid_t pid;
	char buf[10];	//If modified any process-> copy on write technique applied,both process actual buff. mem. location different
	char wbuf[10];
	int fd;

	fd = open("file1.txt",O_WRONLY|O_CREAT,0644);		// "file1.txt" will open in writeonly mode

	pid = fork();		//parent & child share same fd by dup()-> same file object and inode object
	if(pid!=0)
	{
		printf("parent process\n");

		strcpy(wbuf,"SSGM");
		write(fd,wbuf,strlen(wbuf));
		wait();

	}
	else
	{
		printf("child process\n");

		strcpy(buf,"Electro");
		write(fd,buf,strlen(buf));

	}
}
