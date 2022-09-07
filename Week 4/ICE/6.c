#include <stdio.h>

int main(void) {
    int n;
    printf("Enter integer:");
    scanf("%d", &n);

    int copy_of_n = n;

    int reversed_n = 0;
    while (copy_of_n > 0) {
        reversed_n *= 10;
        reversed_n += copy_of_n % 10;
        copy_of_n /= 10;
    }
    
    if (n == reversed_n) {
        printf("%d is a palindrome.\n", n);
    }
    else {
        printf("%d is not a palindrome.\n", n);
    }
}