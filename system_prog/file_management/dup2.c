/***********************************************
* dup2(oldfd,newfd);
* not giving new unused fd but provide access to newfd mention in sys call, before giving access it close silently and reuse again(automatically)
*************************************************/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	printf("start\n");
	int ret,fd,nfd;
	char buf[20]="system programming" ;
	fd = open("1.txt",O_RDWR);

	printf("first\n");
	printf("fd->%d\n",fd);

	printf("second\n");

	if(fd<0)
	{
		printf("open error\n");
		exit(1);
	}

//	write(STDOUT_FILENO,buf,strlen(buf));
	write(1,buf,strlen(buf));

	printf("dup2 sys call\n");

	nfd = dup2(fd,1);

	if(nfd<0)
	{
		printf("open error\n");
		exit(2);
	}
	printf("nfd->%d",nfd);

	char buf1[]="test\n";
	write(fd,buf1,strlen(buf1));

//	write(fd,buf,strlen(buf));

//	close(fd);

	printf("kernal\n");

	strcpy(buf,"hardware\n");
	write(nfd,buf,strlen(buf));


}
