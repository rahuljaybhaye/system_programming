#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#define File "1.txt"

main()
{
	int fd1 =0,fd2=0, ret;
	char buf[]="SSGMCE,Shegaon";
	fd1 = open(File,O_RDONLY);
//	close
//	fd2 = open(File,O_RDONLY);

	if(fd1<0)
	{
		printf("Failed to open the file, fd1 ->%d\n",fd1);
		exit(1);
	}
	printf("return fd1 value is -> %d\n",fd1);
//	printf("fd2->%d\n",fd2);
	ret = read(fd1,buf,6);

	if(ret<0)
	{
		printf("Failed to read data from file\n");
		exit(2);
	}
	printf("ret-> %d bytes read \n ",ret);
//	printf("without null char: %s\n",buf);
	buf[ret] = '\0';
	printf("%s",buf);
//	printf("Hello Embedded Engineer");
//	printf("How are you");

	close(fd1);
}
