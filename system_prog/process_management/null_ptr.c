/*
A null pointer is a pointer which points nothing.

Some uses of the null pointer are:

a) To initialize a pointer variable when that pointer variable isn’t assigned any valid memory address yet.

b) To pass a null pointer to a function argument when we don’t want to pass any valid memory address.

c) To check for null pointer before accessing any pointer variable. So that, we can perform error handling in pointer related code
 e.g. dereference pointer variable only if it’s not NULL.


*/


#include <stdio.h>
int main() {
	char *p= NULL;//initialize the pointer as null.
	printf("The value of pointer is %u ",p);	//output: 0 ,Thus we can use zero insted of null pinter

	if(p == NULL)
	{
		printf("same");

	}
	return 0;
}
