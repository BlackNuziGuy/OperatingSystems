#include <stdio.h>

void sort( int a[], int size){

    int changed = 1;

    while (changed) {
        changed = 0;

        for (int i = 1; i < size ; ++i) {

            if (a[i-1] < a[i]){
                int temp = a[i-1];
                a[i-1] = a[i];
                a[i] =temp;
                changed = 1;
            }
        }

    }

}


int main(){


    int a[] = {4,11,444,2,454,31,17,45};
    sort(a,8);


    for (int i = 0; i < 8; ++i) {

        printf("%d ", a[i]);

    }

    return 0;
}