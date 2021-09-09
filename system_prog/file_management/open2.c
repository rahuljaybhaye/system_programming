#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#define File "1.txt"

void main()
{
	char buf1[] = "Raju12345678";
	char buf2[]= "12345678";

	int fd1,fd2,wret;
	fd1 = open(File,O_RDWR);
	fd2 = open(File,O_RDWR);

//	fd1 = open(File,O_WRONLY);
//	fd2 = open("2.txt",O_WRONLY);
	printf("Files open in write only mode");
	if (fd1<0)
	{
		printf("1.txt file not exist fd1 ->%d\n",fd1);
		exit(0);
	}
	printf("fd1->%d\n",fd1);

	if (fd2<0)

	{
		printf("2.txt file not exist fd2 ->%d\n",fd2);
		exit(1);
	}
	printf("fd2->%d\n",fd2);

	wret = write(fd1,buf1,strlen(buf1));
	close(fd1);
	wret = write(fd2,buf2,strlen(buf2));
	close(fd2);
}
