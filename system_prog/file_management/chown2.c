/*** Program for "chown command" building ******
1.read user name,group name and file name from command line
2.search uid and gid from user and group name 
	a.from etc/passwd
	b.by using system call
3. used chown() system call to change ownership

*********/
#include<fcntl.h>	//open()

main()
{
	int fd;
	int ret1;
	fd = open(/etc/passwd,O_RDONLY);
	ret1 = read(fd)

}
