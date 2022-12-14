#include <stdio.h>

int main(void) {
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input.\n");
        return;
    }

    int product = 1;
    for (int i = 1; i <= n; i++) {
        product *= i;
    }

    printf("%d! = %d\n", n, product);
}