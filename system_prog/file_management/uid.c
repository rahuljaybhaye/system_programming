//#include <pwd.h>
//#include<grp.h>
#include<stdio.h>

#include<unistd.h>
#include<sys/types.h>
//struct passwd *getpwnam(const char * name );
//struct passwd *getpwuid(uid_t uid );

main()
{
	uid_t ret;

	ret= getuid();
	printf("uid-> %d\n",ret);

	ret= geteuid();
	printf("euid-> %d\n",ret);

	ret= getgid();
	printf("gid-> %d\n",ret);

	ret= getegid();
	printf("egid-> %d\n",ret);
}
