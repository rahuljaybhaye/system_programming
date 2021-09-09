/* Client to server communication
	Server wait till client write data

	/* Link libpthread and librt to compiler
	$gcc server.c -l pthread -l rt -o se


***************************  Posix semaphore **********************
NAME
       sem_open - initialize and open a named semaphore

SYNOPSIS
       #include <fcntl.h>           /* For O_* constants
       #include <sys/stat.h>        /* For mode constants 
       #include <semaphore.h>

       sem_t *sem_open(const char *name, int oflag);
       sem_t *sem_open(const char *name, int oflag,
                       mode_t mode, unsigned int value);

      ***  Link with -pthread.

DESCRIPTION
       sem_open() creates a new POSIX semaphore or opens an existing semaphore.  The semaphore is identi‐
       fied by name.
RETURN:
		sucess: Address of new semaphore object
		fail: SEM_FAILED (respective erro no)

**************************************************************************
NAME
       sem_wait - lock a semaphore

SYNOPSIS

	  #include <semaphore.h>

***** int sem_wait(sem_t *sem);
		arg: semaphore object base address

** Link with -pthread.

DESCRIPTION
		- Blocking call on shared memory if semaphore counter zero and we are try to decreament that(not able to -1)

       sem_wait()  decrements  (locks)  the  semaphore  pointed  to  by sem.  If the semaphore's value is
       greater than zero, then the decrement proceeds, and the function  returns,  immediately.   If  the
       semaphore  currently  has the value zero, then the call blocks until either it becomes possible to
       perform the decrement (i.e., the semaphore value rises above zero), or a signal handler interrupts
       the call.

return: succes:- 0 & fail:- -1
***************************************************************************

NAME
       sem_post - unlock a semaphore

SYNOPSIS
       #include <semaphore.h>

       int sem_post(sem_t *sem);

      ** Link with -pthread.

DESCRIPTION
       sem_post()  increments (unlocks) the semaphore pointed to by sem.  If the semaphore's value conse‐
       quently becomes greater than zero, then another process or thread blocked in  a  sem_wait(3)  call
       will be woken up and proceed to lock the semaphore.

RETURN VALUE
		Sucess: 0 , Fail : -1

**********************************************************************************

NAME
       sem_unlink - remove a named semaphore

SYNOPSIS
       #include <semaphore.h>

       int sem_unlink(const char *name);

       ** Link with -pthread.

DESCRIPTION
       sem_unlink() removes the named semaphore referred to by name.  The semaphore name is removed imme‐
       diately.  The semaphore is destroyed once all other processes that have the semaphore  open  close
       it.

RETURN VALUE
		Sucess: 0 , Fail: -1

********************************************************************************************

NAME
       sem_getvalue - get the value of a semaphore

SYNOPSIS
       #include <semaphore.h>

       int sem_getvalue(sem_t *sem, int *sval);

       ** Link with -pthread.

DESCRIPTION
       sem_getvalue()  places  the current value of the semaphore pointed to sem into the integer pointed
       to by sval.

RETURN VALUE
		Sucess: 0, Fail: -1
*/

#include<sys/mman.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<semaphore.h>
#include<stdio.h>		//printf()
#include<string.h>			//memcpy()

int main()
{
	sem_t *sem;
	int fd;
	char *addr;
	int i;
	struct stat buf;
	int sval;

	printf("addr: %p\n",addr);

	// Open/creat shared memory object for read only (If not present in /dev/shm then creat it with 0644 access mode)
	fd = shm_open("/my_shared",O_RDONLY|O_CREAT,0644);

	printf("shm_open return fd: %d\n",fd);

	//**** 1. Crate/open semaphore object and initialize counter value to 0

	sem = sem_open("/demo",O_CREAT,0666,0);

	printf("sem_open return: %p\n",sem);


	// copy statastic of file in structure variable which type struct stat
	fstat(fd,&buf);

	// Map shared mem. object into RAM,update physical frame of RAM to page table of process
	addr = mmap(NULL,buf.st_size,PROT_READ,MAP_SHARED,fd,0);

	printf("mmap return mapping address: %p\n",addr);
	// closing file discriptor (respective file object and inode object will distroy, entry from fd table gets remove)
	close(fd);

	sem_getvalue(sem,&sval);
	printf("semaphore counter value: %d\n",sval);

	printf("server going to block\n");
	//**** 2. Blocking call till client write data and increment semaphore counter, after that we are able to decrement counter successfully
	sem_wait(sem);

	printf("server unblock\n");
	printf("client data rx:\n");
	// Read char. by char. from mapping address of RAM (not from file)
	for(i=0;i<buf.st_size;i++)
	{
		printf("%c",addr[i]);
	}
	printf("\n");
}

