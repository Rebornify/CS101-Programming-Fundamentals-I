#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_palindrome(char string[]) {

}
int main(void) {
    {
        printf("Test 1\n");
        char string[] = "madam";
        bool result = is_palindrome(string);
        printf("Expected:True\n");
        printf("Actual  :%s\n", result ? "True" : "False");
        printf("\n");
    }

    {
        printf("Test 2\n");
        char string[] = "No 'x' in Nixon";
        bool result = is_palindrome(string);
        printf("Expected:True\n");
        printf("Actual  :%s\n", result ? "True" : "False");
        printf("\n");
    }

    {
        printf("Test 3\n");
        char string[] = "bad, chocolate dab";
        bool result = is_palindrome(string);
        printf("Expected:False\n");
        printf("Actual  :%s\n", result ? "True" : "False");
        printf("\n");
    }
}
