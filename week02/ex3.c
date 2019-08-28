#include <stdio.h>

void Triangle(int n);

int main() {

    int n;
    printf("Input size:");
    scanf("%d", &n);
    Triangle(n);
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
