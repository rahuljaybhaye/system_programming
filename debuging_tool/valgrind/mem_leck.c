#include<stdio.h>

int main()
{
	int x = 10;

	int *ptr = (int *)malloc(1*size(int));

	*ptr = 20;

	ptr = &x;
}
