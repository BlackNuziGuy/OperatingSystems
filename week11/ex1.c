#include "stdio.h"
#include "stdlib.h"
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include "string.h"


int main(int argc, char const *argv[])
{
	char *to_write = "This is a nice day";

	struct stat file;
	stat("ex1.txt", &file);
	int fd = open( "ex1.txt", O_RDWR);
	ftruncate(fd, strlen(to_write));

	char *content = mmap(NULL, file.st_size ,
						 PROT_EXEC | PROT_READ |PROT_WRITE,
						 MAP_SHARED, fd, 0);

	strcpy(content, to_write);	
	close(fd);



	
	return 0;
}