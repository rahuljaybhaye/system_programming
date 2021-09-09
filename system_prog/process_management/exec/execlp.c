#include<unistd.h>
#include<stdio.h>

int main()
{
	printf("./a.out -pid: %u\n",getpid());
	execlp("ps","ps","ax",0);
	printf("my process terminated");
}
