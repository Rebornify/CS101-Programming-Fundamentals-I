#include <stdio.h>

int main(void) {
    char c;
    printf("Enter char:");
    scanf("%c", &c);

    if (c >= '0' && c <= '9') {
        printf("%c is a digit\n", c);
    } else if (c >= 'a' && c <= 'z') {
        printf("%c is a lowercase letter\n", c);
    } else if (c >= 'A' && c <= 'Z') {
        printf("%c is a uppercase letter\n", c);
    } else {
        printf("%c is a special character\n", c);
    }
}