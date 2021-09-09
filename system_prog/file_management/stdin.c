/*Read the data from user and print on display without using scanf() and printf() lib. fun. */
// Date:- 09-09-2020
#include<stdio.h>
#include<unistd.h>
main()
{

	char buf[10];
	int ret,val;

	printf("Enter the data\n");
//	ret= read(0,buf,10);
	ret= read(STDIN_FILENO,buf,10);
	printf("read ret value-> %d\n",ret);
	printf("buffer ->%s",buf);

//	val = write(1,buf,ret);
//	val = write(STDOUT_FILENO,buf,ret);

//	printf("write val->%d\n",val);

}
