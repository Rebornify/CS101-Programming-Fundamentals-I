#include <stdio.h>

int my_strspn(char s1[], char s2[]) {
    
}

int main(void) {
    {
        char string[] = "apple123";
        char chars[] = "1234567890";
        printf("Test 1\n");
        printf("Expected:0\n");
        printf("Actual  :%d\n", my_strspn(string, chars));
        printf("\n");
    }

    {
        char string[] = "apple123";
        char chars[] = "abc";
        printf("Test 2\n");
        printf("Expected:1\n");
        printf("Actual  :%d\n", my_strspn(string, chars));
        printf("\n");
    }

    {
        char string[] = "apple123";
        char chars[] = "lap";
        printf("Test 3\n");
        printf("Expected:4\n");
        printf("Actual  :%d\n", my_strspn(string, chars));
        printf("\n");
    }

    {
        char string[] = "";
        char chars[] = "lap";
        printf("Test 4\n");
        printf("Expected:0\n");
        printf("Actual  :%d\n", my_strspn(string, chars));
        printf("\n");
    }
}