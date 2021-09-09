#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

main()
{
	int stat("1.txt",struct stat *buf);
	
}
