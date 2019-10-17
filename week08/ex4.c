#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "string.h"
#include <sys/resource.h> 


int main(int argc, char const *argv[])
{
	
	struct rusage usage;
	int *ptrs[10];


	for (int i = 0; i < 10; ++i)
	{
		ptrs[i] = malloc(1024*1024*10);
		memset(ptrs[i], 0, 1024*1024*10);
		getrusage(RUSAGE_SELF, &usage);
		printf("I am using %ld kbytes\n",usage.ru_maxrss);
		sleep(1);
	}

	for (int i = 0; i < 10; ++i)	free(ptrs[i]);
	

	return 0;
}