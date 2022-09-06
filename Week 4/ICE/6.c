#include <stdio.h>

int main(void) {
    int n;
    printf("Enter integer:");
    scanf("%d", &n);

    int n_modified = n;

    int reversed_n = 0;
    while (n_modified > 0) {
        reversed_n *= 10;
        reversed_n += n % 10;
        n_modified /= 10;
    }
    
    if (n == reversed_n) {
        printf("%d is a palindrome.\n", n);
    }
    else {
        printf("%d is not a palindrome.\n", n);
    }
}