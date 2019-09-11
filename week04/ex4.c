#include <stdlib.h>
#include <stdio.h>


char command[20];


void ask_for_input(){
    printf("$>");
    fgets(command,20,stdin);
}


int main(){
    
    
    while(1) 
    {
        ask_for_input();
        system(command);
    }
    
    
    return 0;
}
 
