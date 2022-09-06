#include <stdio.h>

int main(void) {
    int n;
    printf("Enter positive integer:");
    scanf("%d", &n);

    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    if (sum == n) {
        printf("%d is a perfect number\n", n);
    }
    else {
        printf("%d is not a perfect number\n", n);
    }
}