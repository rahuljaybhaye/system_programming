/*
*****************    pthread_exit - terminate calling thread only not other thread***************

	If used in mainthread only terminate main therad,all other(threads & resorces) remain for execuation

	Normal execuation: exit() at last main thread
									:- All process terminate (all threads terminated)



   #include <pthread.h>

  **** void pthread_exit(void *retval); *******

   Compile and link with -pthread.

	- When a thread terminates, process-shared resources
		(e.g.,  mutexes,  condition  variables,  semaphores,  and  file descriptors) are not released(not destroyed),
		and functions registered using atexit(3) are not called.


	- After the last thread in a process terminates, the process terminates as by calling  exit(3)  with
       an exit status of zero; thus, process-shared resources are released (Destroyed)
*/

#include<pthread.h>
#include<stdio.h>

void *threadfun1(void *arg);
void *threadfun2(void *arg);

int glob= 0;		//global variable

int main()
{
	int ret;
	int loop = 2000;
	pthread_t t1,t2;	//to store thread identifier
	pthread_create(&t1,NULL,threadfun1,&loop);	//lib fun to create new thread
	pthread_create(&t2,NULL,threadfun2,&loop);

	printf("t1: %d\n",t1);
	printf("t2: %d\n",t2);

	printf("terminating main thread\n");
	pthread_exit(&ret);
}

void *threadfun1(void *arg)
{
	int loop;			//local variable
	int i,local;
	printf("thread1 -> loop:%d\n",*(int *)arg);
	loop = *(int *)arg;
	printf("terminating thread1\n");
}


void *threadfun2(void *arg)
{
	int loop;
	int i,local;
	printf("thread2 -> loop:%d\n",*(int *)arg);
	loop = *(int *)arg;

	printf("terminating thread2\n");
}


