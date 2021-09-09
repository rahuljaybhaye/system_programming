/*************************************** Cat command program ************************
By command line argumets
1.read data from file
2. write to shell screen
************************************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
//#define File "1.txt"

void main(int argc, char *argv[])
{
	int fd1, ret;
	char buf[10];		// we have buffer size 10 byte only
	fd1 = open(argv[1],O_RDONLY);	//only reading from file

	if(fd1<0)
	{
		printf("Failed to open the file, fd1 ->%d\n",fd1);
		exit(1);
	}
	printf("return fd1 value is -> %d\n",fd1);


	while( (ret = read(fd1,buf,9))!= 0) 	//buffer size is 10 but we are appending null char at last
	{

		if(ret<0)
		{
			printf("Failed to read data from file\n");
			exit(2);
		}

		buf[ret] = '\0';
		printf("%s",buf);
	}

	close(fd1);
}
