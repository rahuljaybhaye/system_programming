/*********** superuser permission required to execute************/
/*** Progeram to change permissions by using chmod() and fchmod() system calls */

#include<stdio.h>	//printf()
#include<fcntl.h>	//open()
#include<sys/stat.h>	// chmod(), fchmod()
main()
{
	int ret,ret1;
	int fd;
	ret = chmod("1.txt",0666);
	printf("%d\n",ret);

	fd = open("sample.c",O_RDONLY);
	if(fd<0)
	{
		printf("fail to open\n");
		exit(1);
	}
	ret1 = fchmod(fd,0777);
	printf("%d\n",ret1);

}
