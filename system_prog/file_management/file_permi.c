#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
void main()
{
	int fd;
	int fd2;
	//fd = creat("2.txt",0666);
	fd = open("2.txt",O_RDONLY);
	fd2 = fchmod(fd,0722);
	printf("fd2-> %d",fd2);
}
