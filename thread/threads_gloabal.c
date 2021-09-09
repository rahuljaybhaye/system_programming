/******************* Process devide into multiple threads ****************************
   **** pthread_create - create a new thread ****

       #include <pthread.h>

       int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);

			1st arg: Thread identifier base addr (Initially empty when thread will create this update with thread id i.e. index of thread which is present pthread lib thread table)
			2nd arg: Attribute
			3rd arg: Entry point of thread (thread function)
			4th arg: Addr of I/p to thread function

       Compile and link with -pthread. i.e. $gcc prog.c -l pthread


 ***** pthread_join - join with a terminated thread *****

       #include <pthread.h>

       int pthread_join(pthread_t thread, void **retval);

		1st arg: Thread identifier
		2nd arg: return value addr storing pointer

       Compile and link with -pthread.

       The pthread_join() function waits for the thread specified by thread to terminate.  If that thread
       has already terminated, then pthread_join() returns immediately.  The thread specified  by  thread
       must be joinable.

    If  retval is not NULL, then pthread_join() copies the exit status of the target thread
		(i.e. the value that the target thread supplied to pthread_exit(3)) into the location pointed
		to by  retval.

*/



#include<pthread.h>
#include<stdio.h>

void *threadfun1(void *arg);
void *threadfun2(void *arg);

int glob= 0;		//global variable

int main()
{
	int ret;
	void  *stat= &ret;
	int loop = 2000;	//local variable
	pthread_t t1,t2;	//to store thread identifier
	pthread_create(&t1,NULL,threadfun1,&loop);	//lib fun to create new thread
	pthread_create(&t2,NULL,threadfun2,&loop);

	printf("t1: %d\n",t1);
	printf("t2: %d\n",t2);

	pthread_join(t1,&stat);
	pthread_join(t2,&stat);

	printf("Global var- %d\n",glob);

}

void *threadfun1(void *arg)
{
	int loop;			//local variable
	int i,local;
	printf("thread1 -> loop:%d\n",*(int *)arg);
	loop = *(int *)arg;
	for(i=0;i<loop;i++)
	{
		local = glob;
		local++;
		glob = local;
	}
	printf("thread1 ->glob:%d\n ",glob);

}


void *threadfun2(void *arg)
{
	int loop;
	int i,local;
	printf("thread2 -> loop:%d\n",*(int *)arg);
	loop = *(int *)arg;
	for(i=0;i<loop;i++)
	{
		local = glob;
		local++;
		glob = local;
	}
	printf("thread2 ->glob:%d\n ",glob);

}


