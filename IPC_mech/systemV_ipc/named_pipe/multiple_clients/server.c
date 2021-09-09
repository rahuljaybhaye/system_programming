#include<sys/types.h>	//mkfifo()
#include<sys/stat.h>	//mkfifo()
#include<string.h>	//strcpy()
#include<stdio.h>	//printf()
#include<unistd.h>
#include<fcntl.h>

int  client(char *);

int main()
{
	int fd;
	char rbuf[80],wbuf[80];
	mkfifo("srvfifo",0677);		//create serverfifo to lisen
	fd = open("srvfifo",O_RDONLY);
	read(fd,rbuf,80);
	printf("%s",rbuf);
	close(fd);

	client(rbuf);

}

int client(char *ptr)
{
	char buf[80];
	strcpy(buf,ptr);
	printf("client: %s",buf);
}

