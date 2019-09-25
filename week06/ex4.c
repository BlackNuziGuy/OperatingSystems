#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h> 


void sasKe( int i){
	printf("Gotcha! sig = %d\n", i);
}

void sasS( int i){
	printf("Gotcha! sig = %d\n", i);
}

void sasU( int i){
	printf("Gotcha! sig = %d\n", i);
}


int main(int argc, char const *argv[])
{

	signal( SIGKILL, sasKe);
	signal( SIGSTOP, sasS);	
	signal( SIGUSR1, sasU);


	int childID = fork();


	if (childID != 0){

		printf("Use this pid=%d to kill him!!\n", childID);


		exit(0);

	}



	while ( 1 ){


	}
	


	return 0;
}