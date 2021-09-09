/** Program  for append command i.e "append"  by using command line argument **/
#include<stdio.h>
#include<fcntl.h>	// for  open() sys call
#include<unistd.h>	// for read() and  write() sys call
#include<stdlib.h>	//for exit() fun

/*command line argument -> argc calculate no of argument  written at shell,
   char *argv[] is a pointer of type char. array*/

main(int argc,char *argv[])
{
	char buf[20];
	int sfd,dfd,ret,val;
	if(argc != 3)			//checking 3 arguments required for cp command ex. $./a.out <source_file> <Destination_file>
	{
		printf("command not proper\n");
		exit(1);
	}
	sfd = open(argv[1],O_RDONLY);	// open sys call to read second argument i.e. source file 
	if(sfd<0)
	{
		printf("source file not found\n");
		exit(2);
	}
	dfd = open(argv[2],O_WRONLY);	//creat() sys call create new file with third argument at command line  i.e. destination file

	if(dfd<0)
	{
		printf("destination file not able to open\n");
		exit(3);
	}
	lseek(dfd,0,SEEK_END); //Cursor position is at end of destination file

/*copying data from source file to destination file step by step because buffer size is limited
   (every time buffer read new dat)  */

	while((ret= read(sfd,buf,20))!=0)
	{
		if(ret<0)
		{
			printf("source file not able to read\n");
			exit(4);
		}
		val = write(dfd,buf,ret);
		if(val<0)
		{
			printf("write operation to destination file failed\n");
			exit(5);
		}
	}
	close(sfd);
	close(dfd);


}
