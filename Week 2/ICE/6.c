#include <stdio.h>

int main(void) {
    int a;
    printf("Enter side a:");
    scanf("%d", &a);

    int b;
    printf("Enter side b:");
    scanf("%d", &b);

    int c;
    printf("Enter side c:");
    scanf("%d", &c);

    if (a + b < c || a + c < b || b + c < a) {
        printf("It is an invalid triangle.\n");
    } else {
        printf("It is a valid triangle.\n");
    }
}