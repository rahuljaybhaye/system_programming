/* C program to show difference between exit() and _Exit()

* Actually exit() function performs some cleaning before termination of the program like connection termination, buffer flushes etc.
*
* The _Exit() function in C/C++ gives normal termination of a program without performing any cleanup tasks. 
* For example it does not execute functions registered with atexit.
*/
#include<stdlib.h>
#include<stdio.h>

void fun(void)
{
     printf("Exiting");
}

int main()
{
	printf("start\n");
	atexit(fun);
	exit(10);
//	_Exit(10);
}

