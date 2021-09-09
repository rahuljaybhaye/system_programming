#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

//#define File "1.txt"

void main()
{
	int fd;
	fd = open("1.txt",O_RDONLY);
	if(fd<0)
	{
		printf("File not exist\n");
		printf("Fd Val ->%d\n",fd);
		exit(0);
	}
	printf("fd value is -> %d\n",fd);
	sleep(3);
}
