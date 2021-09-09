#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#define File "1.txt"

void main()
{
	int fd1, ret;
	char buf[10];
	fd1 = open(File,O_RDONLY);

	if(fd1<0)
	{
		printf("Failed to open the file, fd1 ->%d\n",fd1);
		exit(1);
	}
	printf("return fd1 value is -> %d\n",fd1);


	ret = read(0,buf,10);

	if(ret<0)
	{
		printf("Failed to read data from file\n");
		exit(2);
	}
	printf("ret-> %d bytes read \n ",ret);
	buf[ret] = '\0';
	printf("%s",buf);
	close(fd1);
}
