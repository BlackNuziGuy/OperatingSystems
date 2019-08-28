#include <stdio.h>
#include <stdlib.h>
#include <float.h>


int main() {

    int a;
    float b;
    double c;


    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;


    printf("INT 'a' has value = %d AND size:%u\n",a, sizeof(a));
    printf("FLOAT 'b' has value = %f AND size:%u\n",b, sizeof(b));
    printf("DOUBLE 'c' has value = %g AND size:%u\n",c, sizeof(c));


    return 0;
}