#include <stdio.h>

int main(void) {
    int height;
    printf("Enter the height of the tree, greater than 9:");
    scanf("%d", &height);

    if (height < 10) {
        printf("Enter a number greater than 9\n");
        return 1;
    }

    for (int i = 0; i < height - 5; i++) {
        for (int j = 0; j < (height - 5) - 1 - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < i * 2 + 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < ((height - 5) * 2 - 1) / 2; j++) {
            printf(" ");
        }
        printf("*\n");
    }
}