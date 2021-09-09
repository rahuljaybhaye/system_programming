#include<sys/sem.h>	//semget(),semctl()
#include<sys/shm.h>	//shmget(),shmat()
#include<stdio.h>	//printf()
#define KEY 199220
 
main()
{
	char data[10]= "RAHUL";
	char *shm;
	int semid;
	int shmid;
	int ret;
	struct sembuf smop;

	printf("waiting till client write data\n");

	semid = semget(KEY,2,IPC_CREAT|0640);	//To create semaphores/semaphore sets/semaphore array
	semctl(semid,0,SETVAL,0);	//First counter initialised with zero (1st semaphore)
	semctl(semid,1,SETVAL,0);	//Second counter initialised with zero value(2nd semaphore)

	shmid = shmget(KEY,512,IPC_CREAT|0640); //To creat shared mem. of size 512 bytes

	shm = shmat(shmid,NULL,0);	// To attched shared mem.-> Entry updated in PCB-> Page table


	//TO block sever until client sent request(client writes data to shared mem)
	smop.sem_num = 0;	// 1st semaphore( 0th index counter)
//	smop.sem_op = -1;	// Decrement operation
	smop.sem_op = -5;	// Decrement operation
	smop.sem_flg = 0;

	semop(semid,&smop,1); //Try to perform decrement operation on counter of 1st semaphore if not then block until clients increment counter value


//	after client writes data to shared mem.
	printf("Data from client: %p - %s \n",shm,shm);

/*	for(i =0;shm[i]!='\0'; i++)
	{
		shm[i + 256] = toggle();
	}
	shm[i + 256] = '\0';
*/
	strcpy(shm+256,data);
	printf("Data writes to shared mem. at location %p ",shm+256);

// After writes the data to half of shared mem. then client should unblock to read that data
//By  using increment 2nd semaphore value

	smop.sem_num = 1 ;	// 2nd semaphore( 1st index counter)
//	smop.sem_op = +1;	//Increment operation on 2nd counter by one
	smop.sem_op = +5;	//Increment operation on 2nd counter by one
	smop.sem_flg = 0;

	semop(semid,&smop,1);
}
