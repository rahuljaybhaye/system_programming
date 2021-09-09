/**************** Program to wirte our own terminal ***************
 Here commands support :- 1. $ps  (ps -ef,ps ax,... )
						  2. $ver
						  3. $quit

cmd2.c -> command line arguments without null char
cmd1.c -> command line arguments with null char to all at end
****Output for both program are same

if(cmdbuf[i]!='\0 '||cmdbuf[i]!='\n')  //No space required between operator and variables



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
		//To clear previous dynamic mem. address
		for(k=0;k<=5;k++)
			mem[k]='\0';
		printf("myshell $>");

		//blocking call
		gets(cmdbuf);

		printf("after gets(),cmdbuf:%s\n",cmdbuf);

//		printf("cmdbuf[11]:%c\n",cmdbuf[11]);

		//printf("args:%p\t %p, %p\n",&args[0],&args[1],args[3]);	//reuired &args[j] to get address not other

/*	//space verification success

		if(arr[2]==' ')
			printf("same\n");
		else
			printf("diff\n");

	//null char check

	if(cmdbuf[i]!='\0')
		printf("filled\n");
	else
		printf("empty\n");

*/

		// Separating cmd line arguments
		// i:- for tracing cmdbuf array
		//j :- Related to char pointer array i.e. args which will store cmd line argument starting address

		for(j;cmdbuf[i]!='\0';j++)
		{
			//printf("i:%d\t j:%d\n",i,j);
			//args[j]=&cmdbuf[i];

			// storing cmd argument addr to arg of type char pointer array
			args[j] = cmdbuf + i;

			// Detecting any space or null char or new line char
			for(i;cmdbuf[i]!=' ';i++)
			{
				//printf("for loop: i=%d\t",i);
				// If any null char or new line char found then assume that end of we are end on inputs
				if(cmdbuf[i]=='\0'||cmdbuf[i]=='\n')
				{
					//printf("before break condition,i:%d\n",i);
					break;
				}
			}

			// replacing new line char or space  with null char
			cmdbuf[i]='\0';
			i++;

		}

	//	args[j]='\0';
	//	sptr = args[0];


//		printf("j final value:%d\n",j);

		printf("before strncmp()\n");
		printf("cmdbuf:%s\n",cmdbuf);

//		printf("args[0]%p:%s,args[1]%p:%s,,args[2]%p:%s",&args[0],args[0],&args[1],args[1],&args[2],args[2]);



/*	** Refer cmd_malloc.c program
**** Program to seprate command line arguments without null char
        (only command-> individuals command line arguments )
*/
		 for(a=0;a<j;a++)
	        {
        	       	 mem[a]= malloc(strlen(args[a]));
               		 //printf("Dynamic memory,%p\n",mem[a]);
               		 for(i=0;i<strlen(args[a]);i++)
              		  {
                       		 sample[0]=mem[a]+i;
                        	//printf("sample addr2%d,%p\n",a,sample[0]);      //indirect$
                        	*sample[0] = *(args[a]+i);                       //storing $
				//printf("char,%c\n",*mem[a]+i);
                	}

       		 }

/*		printf("char,%c\n",*mem[0]);
        	printf("char,%c\n",*(mem[0]+1));

        	printf("char,%c\n",*mem[1]);
        	printf("char,%c\n",*(mem[1]+1));
*/


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
			//	execlp(mem[0],mem[0],mem[1],0);
				exit(0);
			}

		}





	}


}


