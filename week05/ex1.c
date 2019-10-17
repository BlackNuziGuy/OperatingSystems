#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 3


pthread_t thread_id[N];


void *PrintHello(int i) {
    printf("New thread (#%d) says HELLO!\n", thread_id[i]);
    printf("Now thread (#%d) is DED !\n", thread_id[i]);
    pthread_exit(NULL);
}


int main(int argc, char * argv[]) {
    int i;
    
    printf("Now i shall create N=%d threads\n", N);
    
    for (i = 0; i < N; i++) {
        pthread_create(thread_id + i, NULL, PrintHello, i);
        printf("\nNew thread (#%d) was created!!!!\n", (int) thread_id[i], i);
        sleep(1);
    }
        
    return 0;
}
