/*
C strncmp() library function declaration

int strncmp(const char *str1, const char *str2, size_t n)

str1 – First String
str2 – Second String
n – number of characters that needs to be compared.

Return value of strncmp():

This function compares only the first n (specified number of) characters of strings and returns following value based on the comparison.

    0, if both the strings str1 and str2 are equal
    >0, if the ASCII value of first unmatched character of str1 is greater than str2
    <0, if the ASCII value of first unmatched character of str1 is less than str2

*/
#include<string.h>
int main()
{
	int ret;
	ret = strncmp("hello",Hello",5);	//if first char. unmatched then return difference between two values
	printf("ret1 is %d\n",ret);		//chek char by char till no specified 
	printf("%d\t,%d\n",'h','H');	//here return 104 - 72 = 32
}

