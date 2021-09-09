#include<sys/sem.h>	//semget(),semctl()
#include<sys/shm.h>	//shmget(),shmat()
#include<stdio.h>	//printf()
#define KEY 199220
 
main()
{
	char *shm;
	int semid;
	int shmid;
	int ret;
	struct sembuf smop;

	semid = semget(KEY,2,0); /* Access same semaphore object created by server*/

	shmid = shmget(KEY,512,0); //To access existing shared mem. which are matching with key

	shm = shmat(shmid,NULL,0);	// To attched shared mem.
	printf("shared mem. first %p\n",shm);
	printf("shared mem. second %p\n",shm+256);

	strcpy(shm,"rahul");
	printf("client writes the data\n");

	/*client writes data to shared mem.,to inform this update to server we need to increment couter of 1st semaphore */   

	smop.sem_num = 0;	// 1st semaphore( 0th index counter)
//	smop.sem_op = +1;	// Increment operation
	smop.sem_op = +5;	// Increment operation
	smop.sem_flg = 0;

	semop(semid,&smop,1); // Increment operation on counter of 1st semaphore to unblock server

/*Client need to be block until server process the data*/

/*Thus client try to decrement 2nd semaphore counter if not then block */
	smop.sem_num = 1 ;	// 2nd semaphore( 1st index counter)
	//smop.sem_op = -1;	//Decrement operation on 2nd counter by one

	smop.sem_op = -5;	//Decrement operation on 2nd counter by one
	smop.sem_flg = 0;

	semop(semid,&smop,1);

	printf("Server reply back: %p - %s \n",shm+256,shm+256);
}
