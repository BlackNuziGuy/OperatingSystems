#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>
#define MSGSIZE 29



int main() 
{ 
	char* msg = "Child says: \'Hello, pepe\"";  

	//setup a pipe
	int p[2], i; 
	if (pipe(p) < 0) 
		exit(1); 


	//concept a child
	int pid  = fork();


	//parent
	if (pid != 0) write(p[1],msg, MSGSIZE);
	
	// child
	else{
		char dest[MSGSIZE];

		read(p[0],dest, MSGSIZE);
		printf("% s\n", dest); 
	}
    
    
	return 0; 
} 
