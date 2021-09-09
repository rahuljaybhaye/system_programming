/****************************  Posix shared memory **********************

 Posix IPC mechanisum - use only library call
 System V IPC mechanisum - use only system call


NAME
       shm_open, shm_unlink - create/open or unlink POSIX shared memory objects

SYNOPSIS
       #include <sys/mman.h>
       #include <sys/stat.h>       // /* For mode constants
       #include <fcntl.h>          // /* For O_* constants

       int shm_open(const char *name, int oflag, mode_t mode);
			1st arg:  name  specifies  the  shared  memory object  to be created or opened in /dev/shm directory
			2nd arg: oring flag togeter (O_RDONLLY,O_RDWR,O_CREAT,O_EXCL,O_TRUNC)
			3rd arg: access mode with O_CREAT,0644

			return: on success fd value, on fail: -1

       int shm_unlink(const char *name);

       *******  Link with librt (-l rt)



*/

#include<sys/mman.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>		//printf()
#include<string.h>			//memcpy()

int main()
{
	int fd;
	char *addr;
	int i;
	struct stat buf;

	printf("addr: %p\n",addr);

	// Open shared memory object for read only (If not present in /dev/shm then creat it with 0644 access mode)
	fd = shm_open("/my_shared",O_RDONLY|O_CREAT,0644);


	printf("fd: %d",fd);

	// copy statastic of file in structure variable which type struct stat
	fstat(fd,&buf);

	// Map shared mem. object into RAM,update physical frame of RAM to page table of process
	addr = mmap(NULL,buf.st_size,PROT_READ,MAP_SHARED,fd,0);

	printf("after mapping: %p\n",addr);
	// closing file discriptor (respective file object and inode object will distroy, entry from fd table gets remove)
	close(fd);


	// Read char. by char. from mapping address of RAM (not from file)
	for(i=0;i<buf.st_size;i++)
	{
		printf("%c",addr[i]);
	}
	printf("\n");
}
