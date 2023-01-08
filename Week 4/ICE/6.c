#include <stdio.h>

int main(void) {
    int n;
    printf("Enter integer:");
    scanf("%d", &n);

    int temp = n;

    int reversed_n = 0;
    while (temp > 0) {
        reversed_n *= 10;
        reversed_n += temp % 10;
        temp /= 10;
    }
    
    if (n == reversed_n) {
        printf("%d is a palindrome.\n", n);
    } else {
        printf("%d is not a palindrome.\n", n);
    }
}