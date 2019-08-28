#include <stdio.h>


int main(){

    char str[1000];
	printf("Enter the string:");
    fgets(str, 1000,stdin);
	int i = 0;
	
	

	for(; str[i] != '\0'; i++); //Find the last char
	for(;i >= 0; i--){
		putchar(str[i]); //Print in reverse
	};


    return 0;
}