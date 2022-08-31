#include <stdio.h>

int main(void) {
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            printf(" ");
        }
        printf("%c\n", 'A' + (i - 1));
    }
    printf("\n");

    //test commit 4
}