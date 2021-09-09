/*************** IPC mechanisum-> PIPE **************************
	pipe can be use between two related process (parent & child)

***    int pipe(int pipefd[2]);
	    arg: The array pipefd is used to return two file  descriptors  referring to the ends of the pipe.
		 pipefd[0] refers to the read end of the pipe.
		 pipefd[1] refers to the write end of  the pipe.
       	    Return value: On sucess-> 0 and On failuer -> -1



*/

/*	Program :first part parent send data  to child  process by using pipe
		pipe1 : Parent to child communication i.e. fd[2]


*/


#include<unistd.h>	//pipe(),fork()
#include<stdio.h>	//printf()
#include<string.h>	//strlen()


int main()
{
	pid_t pid;	//for storing return value of fork()
	char tbuf[10];	//Userspace buff. for tx data
	char rbuf[10];	//Userspace buff. for tx data
	int ret;	//for storing return value of read()
	int fd[2];	//Parent -> Child communication, fd[0]->read & fd[1]-> write  (One kernel buffer)

	pipe(fd);	//creating pipe (parent -> child)

	printf("fd[1]: %d, fd[1]: %d\n",fd[0],fd[1]);

	pid = fork();

	if(pid>0)
	{
		//For tx data to child (write operation)

		close(fd[0]);	//read() operation closed
		printf("Parent process,pid:%d\n",getpid());
		printf("Parent,fork return:%d\n",pid);
		printf("Parent,Enter data to send to child");

		//**** scanf:- only read till space/ newline (ex. Hey Rahul  :- only read Hey till space)
		//scanf("%s",tbuf);
		//**** gets:- read all input with including space (i.e. Hey Rahul)
		gets(tbuf);

		write(fd[1],tbuf,strlen(tbuf));


	}
	else
	{	// for rx data from parent
		close(fd[1]);	//p->c ,write operation closed
		ret = read(fd[0],rbuf,9);	//Blocking call until parent writes data in respective kernel buffer
		printf("chiled, ret:%d\n",ret);
		rbuf[ret]= '\0';
		printf("child,Data from parent: %s\n",rbuf);


	}

}


