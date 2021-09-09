/******************************************
**** Program to developed own cat command  (display file content on shell)
**********************************************/

#include<sys/mman.h> 		//mmap()
#include<stdio.h>
#include<fcntl.h>
main(int argc,char *argv[])
{
	struct stat buf;
	char *ptr;
	int fd;
	int i;

	fd = open(argv[1],O_RDWR);
	fstat(fd,&buf);
	ptr = mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

	for(i=0; i<buf.st_size;i++)
	{
		printf("%c",ptr[i]);
	}
}
