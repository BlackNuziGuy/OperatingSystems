#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h> 

void sas( int i){

	printf("Gotcha! sig = %d (press ctrl+\\ to kill me)\n", i);

}



int main(int argc, char const *argv[])
{


	while ( 1 ){


		signal( SIGINT, sas);	


	}
	


	return 0;
}