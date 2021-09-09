#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>      //for exit() fun

main(int argc,char *argv[])
{
        char buf[20];
        int first,second,temp,rret,wret;
         if(argc != 3)
        {
                printf("command not proper\n");
                exit(1);
        }

        first = open(argv[1],O_RDWR);

	if(first<0)
        {
                printf("first file not found\n");
                exit(2);
        }

        second = open(argv[2],O_RDWR);

        if(second<0)
        {
                printf("Second file not found\n");
                exit(3);
        }

        temp = creat("temp.txt",0664);

        if(temp<0)
        {
                printf("temp file creation failed\n");
                exit(4);
        }



 /*first operation :-  writing data from first file to temporary file*/

       while((rret= read(first,buf,20))!=0)
        {
                if(rret<0)
                {
                        printf("first file not able to read\n");
                        exit(5);
                }
                wret = write(temp,buf,rret);
                if(wret<0)
                {
                        printf("write operation to temp file failed\n");
                        exit(6);
                }
        }

	lseek(first,0,SEEK_SET);
	lseek(temp,0,SEEK_SET);
	close(temp);

        /* Second operation:- writing data from second file to  first file */

	int ret = ftruncate(first,0);
	printf(" first truncate, ret -> %d",ret);

        while((rret= read(second,buf,20))!=0)
        {
                if(rret<0)
                {
                        printf("second file not able to read\n");
                        exit(7);
                }
                wret = write(first,buf,rret);
                if(wret<0)
                {
                        printf("write operation to first file failed\n");
                        exit(8);
                }

        }

	lseek(second,0,SEEK_SET);
	lseek(first,0,SEEK_SET);

/* Third operation:- writing data from temp file to  second file */

	ret = ftruncate(second,0);
	printf(" second truncate, ret -> %d",ret);

	temp = open("temp.txt",O_RDONLY);

	if(temp<0)
        {
                printf("Not able open temp file for read operation\n");
                exit(9);
        }


       while((rret= read(temp,buf,20))!=0)
        {
                if(rret<0)
                {
                        printf("temp file not able to read\n");
                        exit(10);
                }
                wret = write(second,buf,rret);
                if(wret<0)
                {
                        printf("write operation to second file failed\n");
                        exit(11);
                }

        }

        close(first);
        close(second);
        close(temp);
        remove("temp.txt");
}

