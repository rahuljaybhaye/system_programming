#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

#define File "1.txt"

void main()
{
	int fd1,ret ;
	char buf[10]="hello_u";
//	fd1 = open(File,O_WRONLY | O_CREAT | O_TRUNC,0664);
	fd1 = creat(File,0664);
	printf("Files open in write only mode");
	if (fd1<0)
	{
		printf("1.txt file not exist fd1 ->%d\n",fd1);
		exit(1);
	}
	printf("fd1->%d\n",fd1);

	ret = write(fd1,buf,strlen(buf));
	if(ret <0)
	{
		printf("failed to write");
		exit(2);
	}
	printf("data write is %d bytes",ret);
	close(fd1);
}
