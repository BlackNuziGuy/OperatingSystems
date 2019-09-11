#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


char command[30];


void ask_for_input(){
    printf("$>");
    fgets(command,30,stdin);
}

void run_background(){
    system(command);
}

int main(){
    
    
    while(1) 
    {
        ask_for_input();
        int pid = fork();
        
        if ( pid == 0){
            run_background();
            break;
        }
        
    }
    
    
    return 0;
}
 
