#include <unistd.h> 
#include <stdio.h>



int main(void) {
    
    int n;
    
    int pid = fork();
    
    if ( pid > 0) {
        printf("Hello from parent [%d - %d]\n", getpid(), n);
    } else if (pid == 0) {
        printf("Hello from child [%d - %d]\n", getpid(), n);
    }
     
    return 0;
}
