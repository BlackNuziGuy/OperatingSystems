#include <stdio.h>

void swap( int*a, int*b){

    int temp = *a;
    *a = *b;
    *b = temp;

}


int main() {

    int a,b;
    printf("Please enter two integers:");
    scanf("%d %d",&a,&b);

    swap(&a,&b);

    printf("The values after swap are: %d %d",a,b);


    return 0;
}