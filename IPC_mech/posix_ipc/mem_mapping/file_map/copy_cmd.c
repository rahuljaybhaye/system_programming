/***********************************************************
** Program to developed own copy command ****
***********************************************************

NAME
       memcpy - copy memory area

SYNOPSIS
       #include <string.h>

       void *memcpy(void *dest, const void *src, size_t n);

DESCRIPTION
       The  memcpy()  function copies n bytes from memory area src to memory area dest.  The memory areas
       must not overlap.


*/

#include<sys/mman.h>	// mmap()
#include<stdio.h>	//printf()
#include<fcntl.h>	//open()

main(int argc, char *argv[])
{
	char *sr, *dt;
	struct stat buf;
	int srcfd, dstfd;

	if(argc != 3)
	{
		printf("invalid inputs\n");
		exit(0);
	}
	srcfd = open(argv[1],O_RDONLY);
	fstat(srcfd,&buf);

	sr = mmap(NULL, buf.st_size,PROT_READ,MAP_PRIVATE,srcfd,0);
	close(srcfd);

	dstfd = open(argv[2],O_CREAT|O_RDWR,0640);

	ftruncate(dstfd,buf.st_size);

	dt = mmap(NULL, buf.st_size,PROT_READ|PROT_WRITE, MAP_SHARED,dstfd,0);

	memcpy(dt,sr,buf.st_size);

	close(dstfd);
}
