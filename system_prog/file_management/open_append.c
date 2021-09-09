
// C program to illustrate
// open system call
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

main()
{
	int wret,fd;
//	char buf[]= "hhey ram hey ram";
 	char rbuf[100];
    // if file does not have in directory
    // then file file.txt is created.
//    fd = open("file.txt", O_WRONLY | O_APPEND);
//   fd = open("file.txt", O_RDWR | O_APPEND);
      fd = open("file.txt", O_RDONLY | O_APPEND);

    if (fd<0)
    {
        // print which type of error have in a code
        printf("failed to open file\n");

        // print program detail "Success or failure"
        exit(1);
    }

	printf("fd = %d\n", fd);

//	wret = write(fd,buf,strlen(buf));
	wret = read(fd,rbuf,strlen(rbuf));

    if (wret <0)
    {
        printf("failed to write in file\n");

        exit(2);
    }

	printf("%d bytes wrrite to the file\n",wret);
//	printf("data write is %s\n",buf);
	printf("data write is %s\n",rbuf);

    close(fd);
}

