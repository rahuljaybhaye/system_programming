/****************    Mutex lock & Unlock with threads		*********************
	Threads :
		Threads from same process use same memory(data,bss,heap) which cause updation issue if some threads running parallel
		Updation issue :- ex. If two threads access same global data and running in parallel then global data changes by two threads one after other thus we may not get expected  result
		To minimise updation issue(to protect access to shared memory among threads) we are using  Mutex lock

	Threads with Mutex lock:-

**	pthread_mutex_t mtx;	//mutex object
	mtx = PTHREAD_MUTEX_INITIALIZER;	//Assigning Predefined macro(from pthread.h) to mutex object

**	int pthread_mutex_lock(pthread_mutex_t *mutex)	//Lock mutex object -> Lock critical section
		arg: mutex object base addr

**	int pthread_mutex_unlock(pthread_mutex_t *mutex)	//Unlock mutex object	-> Unlock critical section
		arg: mutex object base addr

*	same mutex object for multiple threads
	Counter: 0 ->State: lock
		 1 ->       unlock

*	pthread_mutex_lock()
	Behaves two manner:
		a. when state: Lock by unother thread -> It block() running thread and not accesing critical section, control goes to remaining threads until time expire
		b.      state: Unlock by self or other thread  ->  It change state from unlock to lock and access critical section

*	pthread_mutex_unlock()
		: Thread which lock mutex mutex object, same thread has to unlock the mutex object
		After executing critical section, State changes from lock to unlock , after this anyone thread can access critical section

*	We have to write lock and unlock outside critical section


*/



#include<pthread.h>	//pthread_create(),pthread_join(),pthread_mutex_lock(),pthread_mutex_unlock()
#include<stdio.h>
void *threadfun1(void *arg);
void *threadfun2(void *arg);

int glob= 0;		//global variable
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;	//Initializing mutext object with Predefined macro (from pthread.h ) 

int main()
{
	int ret;
	void  *stat= &ret;
	int loop = 2000;	//local variable
	pthread_t t1,t2;	//to store thread identifier
	pthread_create(&t1,NULL,threadfun1,&loop);	//lib fun to create new thread
	pthread_create(&t2,NULL,threadfun2,&loop);

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
		pthread_mutex_lock(&mtx);	//lock mutex object(i.e. lock critical section)
		local = glob;
		local++;
		glob = local;
		pthread_mutex_unlock(&mtx);	//Unlock mutex object(i.e. Unlock critical section)
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
		pthread_mutex_lock(&mtx);
		local = glob;
		local++;
		glob = local;
		pthread_mutex_unlock(&mtx);
	}

	printf("thread2 ->glob:%d\n ",glob);

}


