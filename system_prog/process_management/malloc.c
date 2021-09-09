/*
**** Program to seprate command line arguments without null char
	(only command-> individuals command line arguments )

*/

#include<stdlib.h>	//malloc()
#include<stdio.h>
#include<string.h>
int main()
{
	int a,i;
	int j=2;	//no of command in buffer
	char arr[100]={'p','s','\0','a','x','\0','\0'};		//command array
	char *ptr[5];		//char pointer to stored commands including null char
	char *mem[5];		//to stored dynamically created mem. address of char array of command length
	ptr[0]=&arr[0];		//storing command starting address in perticular pointer
	ptr[1]=&arr[3];
	char *sample[1];	//char pointer to access dynamic memory created array for storing string data from ptr(indirectly access command array arr)
	printf("sample addr1,%p\n",sample[0]);
	printf("%s\n",ptr[0]);

	for(a=0;a<j;a++)
	{
		mem[a]= malloc(strlen(ptr[a]));
		printf("Dynamic memory,%p\n",mem[a]);
		for(i=0;i<strlen(ptr[a]);i++)
		{
			sample[0]=mem[a]+i;
			printf("sample addr2%d,%p\n",a,sample[0]);	//indirectly dynamic memory address
			*sample[0] = *(ptr[a]+i);			//storing command char by char to char array (Dynamically created array memory)

		}

	}
	printf("char,%c\n",*mem[0]);
	printf("char,%c\n",*(mem[0]+1));

	printf("char,%c\n",*mem[1]);
	printf("char,%c\n",*(mem[1]+1));


}

