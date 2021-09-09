#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>	//for exit() fun

main(int argc,char *argv[])
{
	char buf[20];
	int first,second,temp,ret,val;
	if(argc != 3)
	{
		printf("command not proper\n");
		exit(1);
	}

	/*first operation :-  writing data from first file to temporary file*/

	temp = creat("temp.txt",0664);
	if(temp<0)
	{
		printf("temp file creation failed\n");
		exit(2);
	}

	first = open(argv[1],O_RDONLY);
        if(first<0)
        {
                printf("first file not found\n");
                exit(3);
        }


	while((ret= read(first,buf,20))!=0)
	{
		if(ret<0)
		{
			printf("first file not able to read\n");
			exit(4);
		}
		val = write(temp,buf,ret);
		if(val<0)
		{
			printf("write operation to temp file failed\n");
			exit(5);
		}
	}
	close(first);
	close(temp);

	/* Second operation:- writing data from second file to  first file */

	second = open(argv[2],O_RDONLY);
        if(second<0)
        {
                printf("Second file not found\n");
                exit(6);
        }


	first = creat(argv[1],0664);
	if(first<0)
	{
		printf("first file creation failed\n");
		exit(7);
	}

	while((ret= read(second,buf,20))!=0)
	{
		if(ret<0)
		{
			printf("second file not able to read\n");
			exit(8);
		}
		val = write(first,buf,ret);
		if(val<0)
		{
			printf("write operation to first file failed\n");
			exit(9);
		}

	}

	close(first);
	close(second);

/* Third operation:- writing data from temp file to  second file */
	temp = open("temp.txt",O_RDONLY);
        if(temp<0)
        {
                printf("temp file not found\n");
                exit(10);
        }


	second = creat(argv[2],0664);
	if(second<0)
	{
		printf("second file creation failed\n");
		exit(11);
	}

	while((ret= read(temp,buf,20))!=0)
	{
		if(ret<0)
		{
			printf("temp file not able to read\n");
			exit(9);
		}
		val = write(second,buf,ret);
		if(val<0)
		{
			printf("write operation to second file failed\n");
			exit(10);
		}

	}
	close(temp);
	close(second);
	remove("temp.txt");
}
