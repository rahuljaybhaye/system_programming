/*********** program to get statastic of file by using system call
	systemcall: fstat()
	command : $stat <file_name>


#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

****  int fstat(int fd, struct stat *statbuf); *********

	functions return information about a file(stastics), in the buffer pointed to by statbuf

         struct stat {
               dev_t     st_dev;         /*  ID of device containing file
               ino_t     st_ino;         /*  Inode number
               mode_t    st_mode;        /* File type and mode
               nlink_t   st_nlink;       /* Number of hard links
               uid_t     st_uid;         /* User ID of owner
               gid_t     st_gid;         /* Group ID of owner
               dev_t     st_rdev;        /* Device ID (if special file)
               off_t     st_size;        /* Total size, in bytes
               blksize_t st_blksize;     /* Block size for filesystem I/O
               blkcnt_t  st_blocks;      /* Number of 512B blocks allocated

               /* Since Linux 2.6, the kernel supports nanosecond
                  precision for the following timestamp fields.
                  For the details before Linux 2.6, see NOTES.

               struct timespec st_atim;  /* Time of last access
               struct timespec st_mtim;  /* Time of last modification
               struct timespec st_ctim;  /* Time of last status change

           #define st_atime st_atim.tv_sec      /* Backward compatibility
           #define st_mtime st_mtim.tv_sec
           #define st_ctime st_ctim.tv_sec

*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<fcntl.h>

int main()
{
	struct stat buf;
	int fd;

	fd = open("1.txt",O_RDONLY);

	fstat(fd,&buf);

	printf("file statastic is:\n\n");
	printf("st_dev: %d\n",buf.st_dev);
	printf("inode no: %d\n",buf.st_ino);
	printf("file access mode: %o\n",buf.st_mode);
	printf("no of hard link: %d\n",buf.st_nlink);
	printf("st_uid: %d\n",buf.st_uid);
	printf("st_gid: %d\n",buf.st_gid);
	printf("st_rdev (special file): %d\n",buf.st_rdev);
	printf("total size: %d bytes\n",buf.st_size);
	printf("Block size: %d\n",buf.st_blksize);
	printf("no of blocks allocated: %d\n",buf.st_blocks);
}
