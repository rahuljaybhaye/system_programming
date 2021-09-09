/****
// C program to implement  server, start first
// wait till request come from any client, after got request send response back
 At server,
	To read data from client -> serverfifo

 At client,
	To send data to server -> serverfifo

       #include <sys/types.h>
       #include <sys/stat.h>

**     int mkfifo(const char *pathname, mode_t mode);

	1st arg: FIFO file name along with path
	2nd arg: access mode(permissions)
	return value : success -> 0, fail -> -1

	Once  you  have  created a FIFO special file in this way, any process can open it for reading or writing, in the same  way  as  an  ordinary  file.
       However,  it  has  to  be open at both ends simultaneously before you can proceed to do any input or output operations on it.  Opening a  FIFO  for
       reading  normally blocks until some other process opens the same FIFO for writing, and vice versa.

*/


#include <stdio.h>	//printf(),scanf()
#include <string.h>	//strlen()
#include <fcntl.h>	//open()
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>	//read(),write()
#include<stdio.h>

int main()
{
	int fd1;

	// Creating the named file(FIFO)
	// mkfifo(<pathname>, <permission>)
	 mkfifo("srvfifo", 0666);		//Serverfifo: for client to server communication
//	printf("mkfifo return value: %d",mret);

	char arr1[80];		//read char user buff
	printf("Server start in only listening mode: \n");

	while (1)
	{

		// Open FIFO for Read only
		fd1 = open("srvfifo", O_RDONLY);
		printf("waiting\n");
		// Read from FIFO
		read(fd1, arr1, sizeof(arr1));

		// Print the read message
		printf("client: %s\n", arr1);
		close(fd1);


	}
	return 0;
}

