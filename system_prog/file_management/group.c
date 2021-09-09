#include<sys/types.h>
#include<grp.h>
#include<stdio.h>

main()
{

	struct group *g;
	char **p;
	char g_name[] = "adm";          //"students";
	g = getgrnam(g_name);
//	g = getgrgid(4);

	printf("gr_name: %s\n",g->gr_name);
	printf("gr_passwd: %s\n",g->gr_passwd);
	printf("gr_gid: %d\n",g->gr_gid);

	printf("gr_mem: %s\n",*(g->gr_mem));
//	printf("gr_mem: %p\n",g->gr_mem);

	for(p= g->gr_mem;*p != NULL; p++)	//printing group members
	{
		printf("%s\n",*p);
	}

}
