/******************** Program to understand gets() lib fun **********************************
	char *gets(char *s);
       gets()  reads a line from stdin into the buffer pointed to by s until either a terminating newline
       or EOF, which it replaces with a null byte ('\0').  No check for buffer overrun is performed

*/

#include<stdio.h>		//printf(), gets()
#include<string.h>		//strlen()

int main()
{
	int i;
	char buf[20];
	printf("Enter input\n");
	gets(buf);

	for(i=0;i<strlen(buf);i++)
	{
		if(buf[i] == '\0')
			printf("null char\n");
		else if(buf[i] == '\n')
			printf("new line char\n");
		else if(buf[i] == ' ')
			printf("space char\n");
		else
			printf("%c\n",buf[i]);
	}

	//printf("%s",buf);

}
