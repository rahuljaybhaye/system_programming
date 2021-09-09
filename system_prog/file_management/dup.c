#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char buf[20];
	int ret;
	int fd = open("2.txt",O_CREAT|O_RDWR,0660);
	if(fd < 0)
	{
		printf("open error");
		exit(1);
	}
	printf("fd-> %d\n",fd);
	int nfd =dup(fd);
	printf("nfd-> %d\n",nfd);


	printf("enter the string\n");
	scanf("%s",buf);
	ret = write(fd,buf,strlen(buf));
	printf("fd ret ->%d\n",ret);

	if(ret < 0)
	{
		printf("write error");
		exit(2);
	}

	printf("enter the string\n");
	scanf("%s",buf);
	ret = write(nfd,buf,strlen(buf));
	printf("nfd ret ->%d\n",ret);

	if(ret < 0)
	{
		printf("write error");
		exit(3);
	}

//	close(nfd);
	close(fd);
	strcpy(buf,"third");
	write(nfd,buf,strlen(buf));
//	close(fd);
	close(nfd);
}



