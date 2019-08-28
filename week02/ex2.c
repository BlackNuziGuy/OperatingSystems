#include <stdio.h>
#include <string.h>


int main(){

    char str[1000];
    fgets(str, 1000,stdin);
    unsigned i = 0,j = strlen(str) - 1 ;
    char a;

    while( i < j){

        a = str[i];
        str[i] = str[j];
        str[j] = a;


        i++,j--;
    }


    printf("%s",str);


    return 0;
}