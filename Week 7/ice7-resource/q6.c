#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_palindrome(char str[]) {
    int len = strlen(str);
    int j = len - 1;

    for (int i = 0; i < len; i++) {
        if (!isalpha(str[i])) {
            continue;
        }

        if (!isalpha(str[j])) {
            i--;
            j--;
            continue;
        }

        if (tolower(str[i]) != tolower(str[j])) {
            return false;
        }
        
        j--;
    }

    return true;
}
int main(void) {
    {
        printf("Test 1\n");
        char str[] = "madam";
        bool result = is_palindrome(str);
        printf("Expected:True\n");
        printf("Actual  :%s\n", result ? "True" : "False");
        printf("\n");
    }

    {
        printf("Test 2\n");
        char str[] = "No 'x' in Nixon";
        bool result = is_palindrome(str);
        printf("Expected:True\n");
        printf("Actual  :%s\n", result ? "True" : "False");
        printf("\n");
    }

    {
        printf("Test 3\n");
        char str[] = "bad, chocolate dab";
        bool result = is_palindrome(str);
        printf("Expected:False\n");
        printf("Actual  :%s\n", result ? "True" : "False");
        printf("\n");
    }
}
