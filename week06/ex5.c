#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h> 


int main(int argc, char const *argv[])
{


	int childID = fork();


	if (childID != 0){

		sleep(10);

		printf("Now me kill bebe!!\n");

		kill(childID, SIGKILL);

		exit(0);

	}



	while ( 1 ){

		sleep(1);
		printf("I'm alive\n");

	}
	


	return 0;
}