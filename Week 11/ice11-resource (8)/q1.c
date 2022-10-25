#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* repeat(char* value, int n) {
    char* result = malloc(sizeof(char) * strlen(value) * n + 1);
    *result = '\0';

    for (int i = 0; i < n; i++) {
        strcat(result, value);
    }
    return result;
}

int main(void) {
    int tc_num = 1;
    {
        char *result = repeat("a", 3);
        printf("Test case %d\n", tc_num++);
        printf("Expected:aaa\n");
        printf("Actual  :%s\n", result);
        free(result);
        printf("\n");
    }

        {
        char *result = repeat("", 3);
        printf("Test case %d\n", tc_num++);
        printf("Expected:[]\n");
        printf("Actual  :[%s]\n", result);
        free(result);
        printf("\n");
    }

    {
        char *result = repeat("Happy Happy Happy ", 5);
        printf("Test case %d\n", tc_num++);
        printf("Expected:[Happy Happy Happy Happy Happy Happy Happy Happy Happy Happy Happy Happy Happy Happy Happy ]\n");
        printf("Actual  :[%s]\n", result);
        free(result);
        printf("\n");
    }
    // char *result = malloc(10 * sizeof(char));
    // memset(result, 0, 10);
    // strcat(result, "abc");
    // printf("%s\n", result);
}
