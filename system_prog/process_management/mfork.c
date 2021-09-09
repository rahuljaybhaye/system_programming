/*
** Program to  calculate no of child process created w.r.t. no of fork()
****  no of process(parent + childs) = 2 (raise n) - 1;
***** Here n = no of fork() in programs
*/
#include<unistd.h>
main()
{
	fork();
	fork();
	fork();
	printf("welcome,pid: %d \n",getpid());
}
