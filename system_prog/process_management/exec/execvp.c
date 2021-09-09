/*
int execv(const char *path, char *const argv[]);
	1st arg: filename along with pathname
	2nd arg: char array base address of arguments
*/

#include<unistd.h>		//execv()
#include<stdio.h>

int main()
{
	char *const argv[] = {"/bin/ps","ps","ax",0};
	printf("my process pid: %u \n",getpid());
	execv(argv[0],&argv[1]);	//2nd argument: string pointer in array not in list
	printf("done\n");
}
