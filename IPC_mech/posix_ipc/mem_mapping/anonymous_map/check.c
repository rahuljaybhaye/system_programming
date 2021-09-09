#include<sys/mman.h>

main()
{
	printf("checking anonymous mapping supported or not by macro\n");

	#ifdef USE_MAP_ANON

		printf("supported successfully\n");
	#endif

	printf("not supported\n");
}
