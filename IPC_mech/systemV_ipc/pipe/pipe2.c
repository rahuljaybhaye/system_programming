/*************** IPC mechanisum-> PIPE **************************
	pipe can be use between two related process (parent & child)

***    int pipe(int pipefd[2]);
	    arg: The array pipefd is used to return two file  descriptors  referring to the ends of the pipe.
		 pipefd[0] refers to the read end of the pipe.
		 pipefd[1] refers to the write end of  the pipe.
       	    Return value: On sucess-> 0 and On failuer -> -1



*/

/*	Program :first part parent send data child, child process that data send output to parent process by using two pipes
		pipe1 : Parent to child communication i.e. fd[2]
		pipe2 : child to parent communication i.e. rc[2]

*/


#include<unistd.h>	//pipe(),fork()
#include<stdio.h>	//printf()
#include<string.h>	//strlen()

int toggle(char *);

int main()
{
	pid_t pid;	//for storing return value of fork()
	char tbuf[10];	//Userspace buff. for tx data
	char rbuf[10];	//Userspace buff. for rx data
	int ret;	//for storing return value of read()
	int fd[2];	//Parent -> Child communication, fd[0]->read & fd[1]-> write  (One kernel buffer)
	int rc[2];	//Child -> Parent communication, rc[0]->read & rc[1]-> write  (Unother kernel buffer)

	pipe(fd);	//creating pipe (parent -> child)
	pipe(rc);	//creating pipe (child -> parent)

	printf("fd[0]: %d\n,fd[1]: %d\n",fd[0],fd[1]);
	printf("rc[0]: %d\n,rc[1]: %d\n",rc[0],rc[1]);

	pid = fork();

	if(pid>0)
	{
		//For tx data to child (write operation)

		close(fd[0]);	//read() operation closed
		printf("Parent process,pid:%d\n",getpid());
		printf("Parent,fork return:%d\n",pid);
		printf("Parent,Enter data to send to child");
		scanf("%s",tbuf);

		write(fd[1],tbuf,strlen(tbuf));

		//For rx from child
		close(rc[1]);
		ret = read(rc[0],rbuf,9);	//Block -> till child writes data kernel buffer
		rbuf[ret]= '\0';
		printf("Parent,Data from child: %s\n",rbuf);
	}
	else
	{	// for rx data from parent
		close(fd[1]);	//p->c ,write operation closed
		ret = read(fd[0],rbuf,9);	//Blocking call until parent writes data in respective kernel buffer
		rbuf[ret]= '\0';
		printf("child,Data from parent: %s\n",rbuf);

		// For tx data to parent
		close(rc[0]);	//read() operation closed
	//	printf("Child,Enter data to send to parent");
	//	scanf("%s",tbuf);

		toggle(rbuf);	//function to toggle data(upper case to lower case or lower case to upper case)

		write(rc[1],rbuf,strlen(rbuf));
	}

}


int toggle(char *ptr)
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
        printf(" \ntoggle Output:%s\n",ptr);


}

