#include <stdlib.h>
#include <stdio.h>


char command[30];


void ask_for_input(){
    printf("$>");
    fgets(command,30,stdin);
}


int main(){
    
    
    while(1) 
    {
        ask_for_input();
        int pid;
       
        pid = fork(); 
        if (pid == 0){
            system(command);
            break;   
        }
    }
    
    
    return 0;
}
 
