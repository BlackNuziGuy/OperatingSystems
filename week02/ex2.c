#include <stdio.h>
#include "string.h"


int main() {

    char str[1000];
    fgets(str, sizeof(str),stdin);


    strrev(str);


    printf("%s",str);


    return 0;
}