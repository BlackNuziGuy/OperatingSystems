#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>

#define MSGSIZE 13 
char* msg1 = "hello, pipe";  


int main() 
{ 
	char dest[MSGSIZE]; 
	int p[2], i; 
    
	if (pipe(p) < 0) 
		exit(1); 

    
	write(p[1], msg1, MSGSIZE); 

    
    read(p[0], dest, MSGSIZE); 

    
    printf("% s\n", dest); 
	
    
	return 0; 
} 
