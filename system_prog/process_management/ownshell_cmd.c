/**************** Program to wirte our own terminal ***************
 Here commands support :- 1. $ps  (ps -ef,ps ax,... )
						  2. $ver
						  3. $quit

Algorithum:-
	1. Read input from user using blocking call gets() lib fun or read() system call
	2. Stored input i.e. cmd in char buffer
	3. Seprate all cmd line arguments
	4. Run command using exec family of call i.e. execl() or execv() types
	5. To run code multiple time place in while loop

*/


#include<string.h>	//strncmp(),strlen()
#include<stdio.h>	//printf()
#include<unistd.h>
#include<sys/wait.h>	//wait()
#include<stdlib.h>      //malloc()

int main()
{

	int i,j,l=0,stat=0,id;
	int k;			//for clearing previous data
	int a;			//counter -> used in seprate command line argument without null char
	char *sptr;
	char  *args[30];	//30 command line arguments base address can store
	char ch;
	char cmdbuf[1024];	//buffer to get input from user(command line arguments) 
	char *sample[1];        //char pointer to access dynamic memory created ar$
	char *mem[5];           //to stored dynamically created mem. address of char array of command length

	while(1)
	{
		i =0;
		j= 0;
		//To clear previous command line arguments
		for(k=0;k<30;k++)
			args[k]='\0';
		//To clear previous command whole input
		for(k=0;k<=1023;k++)
			cmdbuf[k]='\0';

		printf("myshell $>");

		//blocking call
		gets(cmdbuf);

		printf("after gets(),cmdbuf:%s\n",cmdbuf);


		// Separating cmd line arguments
		// i:- for tracing cmdbuf array
		//j :- Related to char pointer array i.e. args which will store cmd line argument starting address

		for(j;cmdbuf[i]!='\0';j++)
		{

			// storing cmd argument addr to arg of type char pointer array
			args[j] = cmdbuf + i;

			// Detecting any space or null char or new line char
			for(i;cmdbuf[i]!=' ';i++)
			{
				// If any null char or new line char found then assume that end of we are end on inputs
				if(cmdbuf[i]=='\0'||cmdbuf[i]=='\n')
				{
					break;
				}
			}

			// replacing new line char or space  with null char
			cmdbuf[i]='\0';
			i++;

		}

		printf("before strncmp()\n");
		printf("cmdbuf:%s\n",cmdbuf);


		// ***********Now do programming for various commands **************

		if(strncmp(args[0],"ver",3)==0)
		{
			printf("simple shell version 1.00,Feb 19,2018\n");
		}

		if(strncmp(cmdbuf,"quit",4)==0)
		{
			exit(0);
		}
	//	printf("%s,%s",args[0],args);

		if(strncmp(args[0],"ps",2)==0)
		{
			id = fork();
			if(id != 0)
			{
				printf("parent process\n");
				wait(&stat);
			}
			else
			{
				execlp(args[0],args[0],args[1],0);
				exit(0);

			}

		}





	}


}


