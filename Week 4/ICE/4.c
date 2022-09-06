#include <stdio.h>

int main(void) {
    int num;
    printf("Enter num:");
    scanf("%d", &num);

    int n = 0;
    while (num != 0) {
        num /= 10;
        n++;
    }
    printf("%d\n", n);
}