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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        printf("%c\n", 'A' + (n - i - 1));
    }
    printf("\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i || j == (n - 1) - i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}