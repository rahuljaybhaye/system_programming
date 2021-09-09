#include<stdio.h>

//function declaration
int sum(int,int);

// Function defination
int sum(int x, int y)
{
	int z;
	printf("In sum function\n");
	z = x+y;
	printf("result z:%d\n",z);
	return z;

}

int main()
{
	int a;
	int b;

	printf("In main function\n");
	//a = 10/0;
	a = 10/3;
	printf("a: %d\n",a);

	// function invocation/calling
	//b = sum(10,20);
	printf("sum is: %d\n",b);

	printf("end\n");


}
