
#include <stdlib.h>	//exit(), _Exit()
#include<stdio.h>
#include <unistd.h>	//_exit()

/*
void exit(int status);

void _Exit(int status);

#include <unistd.h>
void _exit(int status);
*/

main()
{
	printf("first\n");
//	_Exit(1);
	_exit(3);
	printf("second");
}


