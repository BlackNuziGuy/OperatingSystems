#include <stdio.h>

void Triangle(int n);

void Half(int n);

void Rotated(int n);

void Square(int n);

int main() {

    int n, type;
    printf("Input figure type(1-Triangle; 2-Half-triangle; 3-Rotated Triangle; 4-Square):");
    scanf("%d", &type);
    printf("Input size:");
    scanf("%d", &n);
    printf("\n");

    switch (type) {
        case 1 :
            Triangle(n);
            break;
        case 2 :
            Half(n);
            break;
        case 3 :
            Rotated(n);
            break;
        case 4 :
            Square(n);
            break;

        default:
            printf("Wrong input");
    }


    return 0;
}

void Triangle(int n) {
    for (int i = 1; i <= n; ++i) {

        for (int k = 1; k <= (2 * n - 1 - 2 * i - 1) / 2 + 1; ++k) {
            printf(" ");
        }

        for (int j = 1; j <= 2 * i - 1; ++j) {

            printf("*");

        }

        printf("\n");
    }
}

void Half(int n) {
    for (int i = 1; i <= n; ++i) {

        for (int j = 0; j < i; ++j) {

            printf("*");

        }

        printf("\n");
    }
}

void Square(int n) {

    for (int i = 0; i < n; ++i) {


        for (int j = 0; j < n; ++j) {
            printf("*");
        }


        printf("\n");
    }

}

void Rotated(int n) {

    for (int i = 1; i <= n; ++i) {


        if (i > n / 2) {

            for (int j = 0; j < n-i+1; ++j) {

                printf("*");
            }

        } else {

            for (int j = 0; j < i; ++j) {

                printf("*");
            }

        }

        printf("\n");
    }

}
