			// exec : execute file
//  int execl(const char *path, const char *arg, ... /* (char  *) NULL */);
/* 	1st argument-  filename along with pathname
	2nd argument - argumemts till null pointer which of type char *
			( same in execl(), execlp(), and execle()  )

*/
#include<unistd.h>	//execl()
#include<stdio.h>

int main()
{
	printf("my process pid: %u \n",getpid());
	execl("/bin/ps","ps","ax",0);	//2nd argument: string pointer in list not in array format
//	execl("./a.out","a.out",0);
	printf("done\n");	//not print due to process image acquire by command using execl() 
}

