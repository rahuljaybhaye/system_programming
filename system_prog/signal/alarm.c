/*
       unsigned int alarm(unsigned int seconds);

alarm - set an alarm clock for delivery of a signal
*/

#include<unistd.h>	//alarm()
#include<stdio.h>	//printf()

int main()
{
	unsigned int ret;
	pid_t pid;
	pid = getpid();
	printf("pid: %d\n",pid);
	printf("alarm starting\n");
	ret = alarm(50);
	printf("alarm ret: %d",ret);
}
