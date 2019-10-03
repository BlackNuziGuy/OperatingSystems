#include <stdio.h>
#include <stdlib.h>

int main() {

	 //Is there actually a reason to have a 2d array?
	char **s = (char**) malloc(sizeof(char*));
	char foo[] = "Hello World";

	*s = foo;
	printf("The only content of s is *s = %s\n", *s);	
	

	s[0] = foo; // the same as *s = foo
	printf("s[0] is %s\n",s[0]);
	
	return 0;
} 
