#include <stdio.h>

int main(void) {
    int n1;
    printf("Enter n1:");
    scanf("%d", &n1);

    int n2;
    printf("Enter n2:");
    scanf("%d", &n2);

    int n3;
    printf("Enter n3:");
    scanf("%d", &n3);

    if (n1 < n2 && n1 < n3) {
        printf("Smallest is %d\n", n1);
    } else if (n2 < n3) {
        printf("Smallest is %d\n", n2);
    } else {
        printf("Smallest is %d\n", n3);
    }

    if (n1 > n2 && n1 > n3) {
        printf("Largest is %d\n", n1);
    } else if (n2 > n3) {
        printf("Largest is %d\n", n2);
    } else {
        printf("Largest is %d\n", n3);
    }
}