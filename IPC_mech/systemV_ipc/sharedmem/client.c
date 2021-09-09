/*

******** shmget - allocates a System V shared memory segment  ***********

SYNOPSIS
       #include <sys/ipc.h>
       #include <sys/shm.h>

       int shmget(key_t key, size_t size, int shmflg);
			1st arg: user define key
			2nd arg: size of mem. (Physical frame / Page frame) to created in RAM
			3rd arg:  shared mem. flags

				IPC_CREAT :-   Create a new segment.

					(Zero)		   If this flag is not used, then shmget() will find  the  segment associated
							   with key and check to see if the user has permission to access the segment.



DESCRIPTION
       shmget() returns the identifier of the System V shared memory segment associated with the value of
       the argument key.

RETURN VALUE
       On success, a valid shared memory identifier is returned.  On error, -1 is returned, and errno  is
       set to indicate the error.

****************************************************************************************************
NAME
       shmat, shmdt - System V shared memory operations

SYNOPSIS
       #include <sys/types.h>
       #include <sys/shm.h>

       void *shmat(int shmid, const void *shmaddr, int shmflg);

			1st arg: shmid return by shmget() sys. call
			2nd arg: Addr to attached
					NULL:- Memory attached to default virtual address
					spcific addr:- Specify perticular address which we want to attached to that addr
			3rd arg: flags  SHM_EXEC (mem segment:-executable),SHM_RDONLY(Readonly access), SHM_REMAP

		* return : On succes:- Pointer to shared mem. segement
					On error:- -1


******** int shmdt(const void *shmaddr);
			arg:- shared mem. address return by shmat()

			   shmdt()  detaches  the  shared memory segment located at the address specified by shmaddr from the
		       address space of the calling process.  The to-be-detached segment must be currently attached  with
		       shmaddr equal to the value returned by the attaching shmat() call.


*/

#include<sys/shm.h>	//shmget(),shmat()
#include<stdio.h>	//printf()

#define KEY 199220

int main()
{
	int shmid;
	char *shmaddr;

	// Access shared mem. which is associated with key
	shmid = shmget(KEY,20,0);

	printf("shmget return value id : %d\n",shmid);

	// Update shared mem. entry in page table of calling process
	shmaddr = shmat(shmid,NULL,0);

	printf("Shared mem address %x\n",shmaddr);

	printf("Shared mem data %s\n",shmaddr);

}
