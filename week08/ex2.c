#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "string.h"


int main(int argc, char const *argv[])
{
	
	/*
		Well, I have no swap.
		So, yeah.....
	*/
	int *ptrs[10];


	for (int i = 0; i < 10; ++i)
	{
		ptrs[i] = calloc(10,1024*1024);
		memset(ptrs[i], 1, 10*1024*1024);
		sleep(1);
	}

	for (int i = 0; i < 10; ++i)	free(ptrs[i]);
	

	return 0;
}