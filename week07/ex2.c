#include <stdio.h>
#include <stdlib.h>


int main(){
    
    
    int n;
    printf("Enter the desired size:");
    scanf("%d", &n);
    
    int *ar = malloc(sizeof(int)*n);
    
    
    for( int i = 0; i < n; i++ ){
        
        ar[i] = i;
        printf("%d%s",ar[i], (i==n-1)?  "\n":" " );
    
    }
    
    
    free(ar);
    
    
    
    return 0;
}

