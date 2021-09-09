/****************
if(cmdbuf[i]!='\0 '||cmdbuf[i]!='\n')  //No space required between operator and variables


*/


#include<string.h>	//strncmp()
#include<stdio.h>	//printf()
#include<ncurses.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{

	int i,j,l=0,stat=0,id;
	int k;
	char *sptr;
	char  *args[30];	//30 command line arguments base address can store
	char ch;
	char cmdbuf[1024];

	while(1)
	{
		i =0;
		j= 0;
		for(k=0;k<30;k++)		//To clear previous command line arguments
			args[k]='\0';
		for(k=0;k<=1023;k++)
			cmdbuf[k]='\0';
		printf("myshell $>");

		gets(cmdbuf);			//blocking call

		printf("after gets(),cmdbuf:%s\n",cmdbuf);

//		printf("cmdbuf[11]:%c\n",cmdbuf[11]);

		printf("args:%p\t %p, %p\n",&args[0],&args[1],args[3]);	//reuired &args[j] to get address not other

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

		for(j;cmdbuf[i]!='\0';j++)
		{
			printf("i:%d\t j:%d\n",i,j);
			args[j]=&cmdbuf[i];

			for(i;cmdbuf[i]!=' ';i++)
			{
				printf("for loop: i=%d\t",i);
				if(cmdbuf[i]=='\0'||cmdbuf[i]=='\n')
				{
					printf("before break condition,i:%d\n",i);
					break;
				}
			}
			cmdbuf[i]='\0';
			i++;

		}

	//	args[j]='\0';
	//	sptr = args[0];


		printf("j final value:%d\n",j);

		printf("before strncmp()\n");
		printf("cmdbuf:%s\n",cmdbuf);

		printf("args[0]%p:%s,args[1]%p:%s,,args[2]%p:%s",&args[0],args[0],&args[1],args[1],&args[2],args[2]);

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


