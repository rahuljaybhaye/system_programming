
/*
 Posix IPC mechanisum - use only library call
	System V IPC mechanisum - use only system call

****************************************
**** Program to  map file, to read and write file without library and system call ******
**********************************************/
/*mmap()  creates a new mapping in the virtual address space of the call‐
       ing process.

		- map file into RAM of same size as file size,Updation performed at map address reflected in respected file

**     void *mmap(void *addr, size_t length, int prot, int flags,int fd, off_t offset);

	1st arg:       If addr is NULL, then the kernel chooses the address at which to create the  mapping;
		Default: The starting address for the new mapping is specified  in addr.

	2nd arg: size of memory to create

	3rd arg: The argument describes the desired memory protection of the map‐ping (and must not conflict with the open mode of  the  file).   It  is
      		 either  PROT_NONE  or  the  bitwise  OR of one or more of the following flags:
		PROT_EXEC -> Pages may be executed, PROT_READ -> Pages may be read, PROT_WRITE -> Pages may be written, PROT_NONE -> Pages may not be accessed.

	4th arg: int flags:-
		 MAP_SHARED -> Update directly in file (Updates to the mapping are visible to other processes mapping the same region)
		 MAP_PRIVATE -> Updates to the mapping are not visible to other processes mapping the  same  file

	5th arg: fd value of file which want to map into RAM

	Return: addr of mapped area(success)
*/






#include<sys/mman.h> 		//mmap()
#include<stdio.h>
#include<fcntl.h>
main()
{
	struct stat buf;
	char *ptr;
	int fd;
	int i;

	fd = open("1.txt",O_RDWR);
	fstat(fd,&buf);			//to get inode object data

	// MAP_SHARED:- Modification done in process memory gets reflected in file
	ptr = mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	// MAP_PRIVATE:- Modification done in process memory will not reflected in file
	ptr = mmap(NULL,buf.st_size,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);

	ptr[0]= 'a';
	for(i=0; i<buf.st_size;i++)
	{
		printf("%c",ptr[i]);
	}

}
