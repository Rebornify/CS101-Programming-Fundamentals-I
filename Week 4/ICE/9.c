#include <stdio.h>

int main(void) {
    int num;
    printf("Enter num:");
    scanf("%d", &num);

    int binaryNum[32];
    int i = 0;

    while (num > 0) {
        binaryNum[i++] = num % 2;
        num /= 2;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }

    printf("\n");
}