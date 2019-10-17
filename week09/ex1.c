#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void decToBinary(unsigned int n)
{
    // array to store binary number
    int binaryNum[32]= {0};

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = 31 ; j >= 0; j--)
        printf("%d",binaryNum[j]);
}

int n;
int *pages;
uint64_t *ages;

///returns -1 if not found
 int search_page(unsigned int data){

     int found = -1;
    for (int i = 0; i < n; ++i) {
        if (pages[i] == data ){
            found = i;
            return found;
        }
    }

    return found;
}


int find_worst(){

    uint64_t min = ages[0];
    int ind = 0;

    for ( int i = 0; i < n; ++i)
        if (ages[i] < min ) {
            min = ages[i];
            ind = i;
        }

    return ind;
}


void make_time_pass( unsigned int num){
    for (int i = 0; i < n; ++i) {
        ages[i] = (ages[i] >> 1) ;

        if ( i == num ){
            ages[i] = ages[i] | ( 1ull << (sizeof(uint64_t)*8 -1 ) ) ;
        }
    }
}


int main(){

    printf("Enter the number of page frames:");
    scanf("%d",&n);


    //Initialize
    pages = (int*)malloc(sizeof(int) * n);
    ages  = (uint64_t *) malloc(sizeof(uint64_t)  * n);
    for (unsigned int i = 0; i < n; ++i)  ages[i] = (pages[i] = 0);


    int data, found, misses = 0, hits = 0;
    FILE *inp = fopen("Lab 09 input.txt","r");


    while(!feof(inp)){

        fscanf(inp,"%d", &data);

        if ( (found = search_page(data)) != -1 ){ // -1 if not found
            hits++;
        }
        else{
            misses++;
            found = find_worst();  // Reuse found
            pages[found] = data; ages[found] = 0;
        }
        make_time_pass( found ); // Do it for both
    }


    printf("Hits:%d Misses:%d \nHitRate:%f", hits, misses , (float)hits/(float)misses);


    return  0;

}