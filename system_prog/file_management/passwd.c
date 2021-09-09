/**** Program to extract information from "etc/passwd" file by using getpwnam() or getpwuid()	*******************/

#include<pwd.h>		//getpwnam(),getpwuid()
#include<sys/types.h>   //getpwnam(),getpwuid() 



main()
{
	struct passwd *p;
//	char user[]="chetan";
//	p = getpwnam(user);	//return pointer of structure for specified user name
	p = getpwnam("chetan");	//return pointer of structure for specified user name
	
//	p = getpwuid(1001);	//return pointer of structure for specified user-id
	printf("%p",p);

	printf("pw_name: %s\n",p->pw_name);	//accessing memory at pointer address by arrow operator
	printf("pw_passwd: %s\n",p->pw_passwd);
	printf("pw_uid: %d\n",p->pw_uid);
	printf("pw_gid: %d\n",(int)p->pw_gid);

}
