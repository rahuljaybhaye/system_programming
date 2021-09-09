/*  ****** Program used in pipe.c file
	program to toggle word i.e upper case to lower case and from lower to upper case

*/

#include<stdio.h>

int toggle(char *);		//fun declaration/signature/prototype

int main()
{
	char buf[]={"SSGM Elcetronic Solutions pvt ltd"};
	toggle(buf);		//fun invocation
/*	int ret =strlen(buf);
	int i;

	for(i=0;i<ret;i++)
	{
		if(65<=buf[i] && buf[i]<=90)
		{
			printf("%d:uppper\t",i);
			buf[i] = buf[i] + 32;
		}

		else if(97<=buf[i] && buf[i]<=122)
		{
			printf("%d:lower\t",i);
			buf[i] = buf[i] - 32;
		}
		else
		{
			printf("%d:unknown\t",i);
		}

	}
*/
	printf("Output:%s\n",buf);
}


int toggle(char *ptr)				//fun body/ defination
{
	int i;
	int ret =strlen(ptr);
        printf("toggle fun,ret: %d\n",ret);

	for(i=0;i<ret;i++)
        {
                if(65<= ptr[i] && ptr[i]<=90)
                {
                        printf("%d:uppper\t",i);
                        ptr[i] = ptr[i] + 32;
                }

                else if(97<= ptr[i] && ptr[i]<=122)
                {
                        printf("%d:lower\t",i);
                        ptr[i] = ptr[i] - 32;
                }
                else
                {
                        printf("%d:unknown\t",i);
                }

        }
        printf(" toggle Output:%s\n",ptr);


}
