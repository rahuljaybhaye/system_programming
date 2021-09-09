#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main()
{
	char buf[]= "Device driver, system programming,c, python";
	int fd;
	int wret, ret;

	fd = open("3.txt",O_WRONLY);

	if(fd<0)
	{
		printf("failed to open file\n");
		exit(1);
	}

	lseek(fd,0,SEEK_SET);
//	ret = ftruncate(fd,0);
	ret = ftruncate(fd,5);
	if(ret<0)
	{
		printf("failed to truncate file\n");
		exit(2);
	}
	printf("truncate file successfully ret-> %d\n",ret);

/*
	wret = write(fd,buf,strlen(buf));

	if(wret<0)
	{
		printf("failed to write file\n");
		exit(3);
	}
*/
	close(fd);
}
