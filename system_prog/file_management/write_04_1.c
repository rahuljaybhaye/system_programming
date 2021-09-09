#include<stdio.h>
#include<fcntl.h>	//open()
#include<unistd.h>	//read(), write(), close()
#include<stdlib.h>	//exit()
#include<string.h>
#define File "1.txt"

void main()
{
	int fd1, ret,no;
	char wbuf[]="Rahul Jaybhaye";
	char rbuf[]= "Hello Mr.Entrepreneur";
	fd1 = open(File,O_RDWR);
//	fd1 = open(File,O_WRONLY);
//	fd1 = open("/dev/mydev",O_WRONLY);
//	fd1 = open(File,O_WRONLY);

	if(fd1<0)
	{
		printf("Failed to open the file, fd1 ->%d\n",fd1);
		exit(1);
	}
	printf("return fd1 value is -> %d\n",fd1);

	printf(" rbuf data: %s\n",rbuf);

//write to the file

//	lseek(fd1,0,SEEK_SET);	//at the begining of file

//	ret = write(fd1,buf,strlen(buf));
	ret = write(fd1,wbuf,strlen(wbuf));

	if(ret<0)
	{
		printf("Failed to write data to file\n");
		exit(2);
	}

	printf("ret-> %d bytes write \n ",ret);
//	wbuf[ret] = '\0';
	printf("%s\n",wbuf);


// Read from file you just write
//	lseek(fd1,0,SEEK_END);	//at the end of file

	lseek(fd1,0,SEEK_SET);	//at the begining of file

	no = read(fd1,rbuf,14);
	if(no<0)
	{
		printf("failed to read data from file\n");
		exit(3);
	}
	printf("%d read from file\n",no);
	printf("without null char data read is: %s\n",rbuf);

	rbuf[no]= '\0';
	printf("data read is: %s",rbuf);

	close(fd1);

}
