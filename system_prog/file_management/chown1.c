/*********** superuser permission required to execute************/
/*** Progeram to change ownership(user and group) by using chown() and fchown() system calls */

#include<unistd.h>	//chown(), fchown()
#include<stdio.h>	//printf()
#include<fcntl.h>	//open()

main()
{
	int ret,ret1;
	int fd;

	ret = chown("sample.c",1001,1002);
//	ret = chown("sample.c",1000,1000);
	printf("%d\n",ret);

	fd = open("1.txt",O_RDONLY);
	if(fd<0)
	{
		printf("fail to open\n");
		exit(1);
	}
	ret1 = fchown(fd,1001,1002);
	printf("%d\n",ret1);

}
