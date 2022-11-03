#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_repeated_lowercase_letters(char *str) {
    int count[26] = {0};
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            count[*str - 'a']++; 
        }
        str++;
    }

    char *result = calloc(27, sizeof(char));
    char *temp = result;

    for (int i = 0; i < 26; i++) {
        if (count[i] > 1) {
            *temp++ = 'a' + i;
        }
    }
    return result;
}

int main(void) {
    int tc_num  = 1;
    {
        char *result = get_repeated_lowercase_letters("abca");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:a\n");
        printf("Actual  :%s\n", result);
        free(result);
        printf("\n");
    }

    {
        char *result = get_repeated_lowercase_letters("The cat jumps over the wall.");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:aehlt\n");
        printf("Actual  :%s\n", result);
        free(result);
        printf("\n");
    }

    {
        char *result = get_repeated_lowercase_letters("...");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:[]\n");
        printf("Actual  :[%s]\n", result);
        free(result);
        printf("\n");
    }
}