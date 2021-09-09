#include<stdlib.h>
int main()
{
	printf("started system process\n");
	printf("pid:%d\n",getpid());
	int ret = system("ps -ef");
//	system("./fork");
	printf("return value is %d\n",ret);
	printf("my process terminated\n");
}
