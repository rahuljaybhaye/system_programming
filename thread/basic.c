/**************
*	Program to create new thread
*********************/
/*
  gcc compilar knows only std. C lib funtions(function defination),which is present in libc.so library
	function declaration/prototype/signature ----> respective header files

 Threads lib. fun. present in libpthread.so library, compilar doesn't know about this

 when we are using other than std. C lib. fun in our program,we must link that corrosponding library during compilation time, by follow syntax

***	$gcc  <program_name> -l pthread  ******************

***	// Library fun to create new thread

*       int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);

	1st: Thread identifier base addr,Initially thread id empty after pthread_creat() succesful it contained  unique value(index value) 
	2nd: Thread attribuates/flags pointer
		 The attr argument points to a pthread_attr_t structure  whose  contents
       		are  used  at  thread creation time to determine attributes for the new
       		thread;

		If  attr is NULL ->the thread is created with default attributes.
	3rd: Entry point of thread(function name)
	4th: Arguments which are i/p to thread entry point

***  //Block or Wait till perticular thread terminate

*  int pthread_join(pthread_t thread, void **retval);
	1st: thread id
	2nd: double poiner-> return value of thread



*/
#include<stdio.h>
#include<pthread.h>	//pthred_create(),pthred_join()
#include<string.h>
void * thread_fun(void *arg );

main()
{
	pthread_t ti;
	int ret;
	void *stat = &ret;
	pthread_create(&ti,NULL,thread_fun,"Hello");
	printf("In main thread\n");
	pthread_join(ti,&stat); //Blocking call, return value of new thread sotred in stat
	printf("%d\n",stat);
}

void *thread_fun(void *str)
{
	printf("In thread1\n");
	printf("%s\n",(char *)str);
	return strlen(str);
}
