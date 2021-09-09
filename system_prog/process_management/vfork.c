/*    pid_t vfork(void);
      * vfork() differs from fork(2) in that the calling  thread  is  suspended
       until  the  child  terminates
	(either normally, by calling _exit(2), or
	 abnormally, after delivery of a fatal signal), or it makes  a  call  to
         execve(2).
       Until that point, the child shares all memory with its par‐
       ent, including the stack.  The child must not return from  the  current
       function  or  call exit(3) (which would have the effect of calling exit
       handlers established by the parent process and  flushing  the  parent's
       stdio(3) buffers), but may call _exit(2).

	*Both parent and child have same memory,if we change variable data in child that reflect in parent



*/
#include<unistd.h>	//vfork()
#include<sys/types.h>
#include<stdio.h>	//printf()
#include<stdlib.h>	//exit()
int main()
{
	int x = 12;
	pid_t ret;
	ret = vfork();
	if(ret!=0)
	{
		printf("parent proces, x:%d\n",x);
		printf("parent, ret:%d,pid:%d\n",ret,getpid());
		exit(0);
	}
	else
	{
		x = 44;
		printf("child process, x:%d\n",x);
		printf("child,ret:%d,pid:%d\n",ret,getpid());
		exit(1);
	}
}
