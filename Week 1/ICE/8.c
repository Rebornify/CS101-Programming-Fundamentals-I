#include <stdio.h>

int main(void) {
    int n;
    printf("Enter number:");
    scanf("%d", &n);

    int n1 = n / 10000;
    n -= n1 * 10000;

    int n2 = n / 1000;
    n -= n2 * 1000;

    int n3 = n / 100;
    n -= n3 * 100;

    int n4 = n / 10;
    n -= n4 * 10;

    int n5 = n;

    int sum = n1 + n2 + n3 + n4 + n5;
    printf("%d + %d + %d + %d + %d = %d\n", n1, n2, n3, n4, n5, sum);
}