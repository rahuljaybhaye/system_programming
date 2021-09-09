/********* execl, execlp, execle, execv, execvp, execvpe - execute a file*******/

// int execl(const char *path, const char *arg, ... /* (char  *) NULL */);
// int execv(const char *path, char *const argv[]);

// int execlp(const char *file, const char *arg, ...  /* (char  *) NULL */);
// int execvp(const char *file, char *const argv[]);

// int execle(const char *path, const char *arg, ... /*, (char *) NULL, char * const envp[] */);

// int execvpe(const char *file, char *const argv[], char *const envp[]);

#include<unistd.h>

int main()
{
	char *const argv[] = {"ps","ax",(char*)NULL};		//argument of type char *const array type -> address is fixed but arguments changable
	char *const envp[]= {"PATH= .:/bin:/usr/bin",0};		//environment parameters

	printf("process id: %d\n",getpid());

//	execl("/bin/ps","ps","ax",(char *)NULL);		//2nd arg: argument list

//	execv("/bin/ps",argv);

//	execlp("ps","ps","ax",(char *)NULL);			//1st arg:filename
//	execvp("ps",argv);

//	execle("/bin/ps","ps","ax",(char *)NULL,envp);		//1st arg: must pathname  along with file name
//	execvpe("/bin/ps",argv,envp);


}
