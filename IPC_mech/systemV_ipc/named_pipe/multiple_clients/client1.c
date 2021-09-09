/* C program to implement client communication
// It will first send request to server by using server fifo then  wait till response back from server by using client fifo

 At server,
        To read data from client -> serverfifo
        To send data to client -> clientfifo

 At client,
        To read data from server -> clientfifo
        To send data to server -> serverfifo

**   char *fgets(char *s, int size, FILE *stream);
	1st arg:- char buffer base address
	2nd arg:- max size to read
	3rd arg:- file object name/address

       fgets()  reads  in  at most one less than size characters from stream and
       stores them into the buffer pointed to by s.  Reading stops after an  EOF
       or  a  newline.   If  a newline is read, it is stored into the buffer.  A
       terminating null byte ('\0') is stored after the last  character  in  the
       buffer.


*/


#include <stdio.h>	//printf(),scanf()
#include <string.h>	//strlen(),strcat()
#include <fcntl.h>	//open()
#include <sys/stat.h>	//mkfifo()
#include<sys/types.h>	//mkfifo()
#include<unistd.h>	//read(),write(),getpid()
//#include<>
int main()
{
	int fd1,fd2;
	char str1[80];	//read user buffer
	char str2[80];	// write user buffer

	char fifo[20]="clififo";
	char arr[6];
	pid_t pid;
	pid = getpid();
	strcpy(arr,char(pid));
	printf("arr:%s\n",arr);
	//strcat(fifo,pid);
	printf("fifo:%s\n",fifo);
	// Creating the named file(FIFO)
	// mkfifo(<pathname>,<permission>)
	mkfifo(fifo, 0666);		//Clientfifo:- For server to client communication


	while (1)
	{

		// First open in write mode and write
		// string taken from user.
		fd1 = open("srvfifo",O_WRONLY);
		printf("Enter data to send\n");
		fgets(str2, 80, stdin);
		write(fd1, str2, strlen(str2)+1);
		close(fd1);

		// Now open in read only and read
		fd2 = open(fifo,O_RDONLY);
		printf("waiting\n");
		read(fd2, str1, 80);

		// Print the read string and close
		printf("server: %s\n", str1);
		close(fd2);

	}
	return 0;
}

