#include <stdio.h>

int main(void) {
    int n1;
    printf("Enter n1:");
    scanf("%d", &n1);

    int n2;
    printf("Enter n2:");
    scanf("%d", &n2);

    if (n2 % n1 == 0) {
        printf("%d is a factor of %d\n", n1, n2);
    } else {
        printf("%d is not a factor of %d\n", n1, n2);
    }
}