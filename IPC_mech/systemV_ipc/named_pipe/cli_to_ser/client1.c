/* C program to implement client communication
// It will first send request to server by using server fifo then  wait till response back from server by using client fifo

 At server,
        To read data from client -> serverfifo

 At client,
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
#include <string.h>	//strlen()
#include <fcntl.h>	//open()
#include <sys/stat.h>	//mkfifo()
#include <sys/types.h>	//mkfifo()
#include <unistd.h>	//read(),write()

int main()
{
	int fd1,fd2;

	char str2[5];	// write user buffer
	printf("client start only in sending mode: \n");

	while (1)
	{

		// First open in write mode and write
		// string taken from user.
		fd1 = open("srvfifo",O_WRONLY);
		printf("Enter data to send\n");
		fgets(str2, 5, stdin);
		write(fd1, str2, strlen(str2)+1);
		close(fd1);



	}
	return 0;
}

