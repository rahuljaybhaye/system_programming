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
#include<stdio.h>
#include<string.h>

int main()
{
	int fd;
	char *addr;

	printf("addr: %x %p\n",addr,addr);

	// Shared mem. object :- If not available in /dev/shm directory then creat it with given 0644 access mode
	//and open it for read & write purpose, if available then open it for read & write purpose
	fd = shm_open("/my_shared",O_CREAT|O_RDWR,0644);

	printf("fd: %d",fd);

	// Change size of file(shared mem. object) from 0 bytes to 10 bytes (required after creation of object)
	ftruncate(fd,10);

	// Map shared mem. object(file/device) into RAM and update physical frame no to page table of process
	addr = mmap(NULL,10,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	printf("after mapping: %x, %p\n",addr,addr);

	// close file discriopor(Distory file object and inode object,delete fd value from fd table of process)
	close(fd);

	// copy 5 bytes form src memory area("Hello") to dest (addr) memory area
	memcpy(addr,"Shambu",6);

}
