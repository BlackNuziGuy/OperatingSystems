#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h> 
#include <sys/wait.h>

int main(int argc, char const *argv[])
{

	//setup the pipe
	int p[2];
	pipe(p);

	printf("The pipe was set up\n");
	

	//Create ehe first child;
	printf("The child_1 is born\n");
	int childID = fork();
	if (childID != 0){


		//bear the second child;
		printf("The child_2 is born\n");
		int childID_2 = fork();


		//Main program action
		if ( childID_2 != 0 ){

			int *kostil = &childID_2;

			//Send ID of child#2 to the child#1
			printf("Second child's PID = %d was sent to the child_1.\nNow waiting....\n", childID);
			write( p[1], kostil, sizeof(childID));

			waitpid( childID_2, NULL, WUNTRACED);

			//Just to make it prettier
			waitpid(childID, NULL, 0);

			exit(0);
		}

	} 
	else{


		//Child #1 action
		printf("Child_1 waitng....\n");
		int *child_2_ID; read(*p, child_2_ID, sizeof(childID));

		sleep(2);
		kill(*child_2_ID, SIGSTOP);
		printf("Child_2 is DED now.\n");
	}
	return 0;
}