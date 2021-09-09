// int execle(const char *path, const char *arg, .../*, (char *) NULL, char * const envp[] */);
// int execvpe(const char *file, char *const argv[],char *const envp[]);
/*


*/
#include<unistd.h>
#include<stdio.h>

int main()
{
	char *const ps_argv[]= {"ps","ax",0};
	char *const ps_envp[] = {"PATH= .:/usr/bin:/bin",0}; //array of char *const type , thus storing address of strings
	printf("start\n");
	printf("process id is : %d\n",getpid());
	execle("/bin/ps","ps","ax",0, ps_envp); //2nd arg: string pointer in list not array

//	execvpe("/bin/ps",ps_argv,ps_envp);
}
