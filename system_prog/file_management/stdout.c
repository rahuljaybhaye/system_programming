/*Read the data from user and print on display without using scanf() and printf() lib. fun. */
// Date:- 09-09-2020

/* write() -> sys_write() -> display driver routine() -=> (intrerrupt handler fun)-=> display device
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
main()
{

	char buf[10]= "embedded";
	int ret,val;

/*	printf("start");
	printf("Enter the data\n");
	ret= read(0,buf,10);
	printf("read ret value-> %d\n",ret);
	printf("buffer ->%s\n",buf);
*/
//	write(1,buf,10);
	val = write(STDOUT_FILENO,buf,strlen(buf));

//	val = write(1,buf,strlen(buf));

	printf("write bytes are val->%d\n",val);

}
