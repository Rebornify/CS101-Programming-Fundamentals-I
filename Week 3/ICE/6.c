#include <stdio.h>
#include <math.h>

int main(void) {
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("--\\|/-");
    }
    printf("\n");

    for (int i = n; i > 0; i--) {
        printf("%d ", i * i);
    }
    printf("\n");

    for (int i = 1; i <= n; i++) {
        printf("%d%d%d ", i, i + 1, i + 2);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("%c", 'A' + i);
        printf("%c", 'A' + i + 'a'-'A');
    }
    printf("\n");


    int sum = 0;
    for (int i = n; i > 0; i--) {
        printf("%d ", i);
        sum += i;
    }
    printf("(Sum: %d)\n", sum);
    printf("\n");
    
    int product = 0;
    for (int i = 1; i <= n; i++) {
        product += pow(10, i - 1) * i;
        printf("%d\n", product);
    }
}