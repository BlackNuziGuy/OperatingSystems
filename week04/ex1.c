#include <unistd.h> 
#include <stdio.h>



int main(void) {
    
    int pid, n;
    
    if ((pid = fork()) > 0) {
        printf("Hello from parent [%d - %d]\n", pid, n);
    } else if (pid == 0) {
        printf("Hello from child [%d - %d]\n", pid, n);
    }
     
    return 0;
}
