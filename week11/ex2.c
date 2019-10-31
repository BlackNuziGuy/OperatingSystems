#include <stdio.h>
#include "stdlib.h"
#include <unistd.h>


int main(){
	
	char buf[20];

	setvbuf( stdin, buf, _IOFBF, 20 );


	printf("H");
	sleep(1);
	printf("e");
	sleep(1);
	printf("l");
	sleep(1);
	printf("l");
	sleep(1);
	printf("o\n");
	sleep(1);


	return 0;
}