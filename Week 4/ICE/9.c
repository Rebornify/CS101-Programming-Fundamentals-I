#include <stdio.h>

int main(void) {
    int num;
    printf("Enter num:");
    scanf("%d", &num);

    int binary = 0;
    int remainder;
    int place = 1;
    while (num > 0) {
        remainder = num % 2;
        num /= 2;

        binary += remainder * place;
        place *= 10;
    }
    printf("%d\n", binary);
}