#include <stdio.h>

void my_strlwr(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 'a' - 'A';
        }
        i++;
    }
}

int main(void) {
    {
        char string[] = "APPLE";
        my_strlwr(string);
        printf("Test 1\n");
        printf("Expected:apple\n");
        printf("Actual  :%s\n", string);
        printf("\n");
    }

    {
        char string[] = "";
        my_strlwr(string);
        printf("Test 2\n");
        printf("Expected:><\n");
        printf("Actual  :>%s<\n", string);
        printf("\n");
    }

    {
        char string[] = "There is 1 APPLE.";
        my_strlwr(string);
        printf("Test 3\n");
        printf("Expected:there is 1 apple.\n");
        printf("Actual  :%s\n", string);
        printf("\n");
    }

    {
        char string[] = "happy";
        my_strlwr(string);
        printf("Test 4\n");
        printf("Expected:happy\n");
        printf("Actual  :%s\n", string);
        printf("\n");
    }
}