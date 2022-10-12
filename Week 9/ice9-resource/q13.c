#include <stdio.h>


int main(void) {
    {
        char string[] = "aaaabbcc";
        int result = remove_consecutive_duplicates(string);
        printf("Test 1\n");
        printf("Expected:abc 3\n");
        printf("Actual  :%s %d\n", string, result);
        printf("\n");
    }

    {
        char string[] = "abcaaaadad";
        int result = remove_consecutive_duplicates(string);
        printf("Test 2\n");
        printf("Expected:abcadad 7\n");
        printf("Actual  :%s %d\n", string, result);
        printf("\n");
    }

    {
        char string[] = "abbbbbb";
        int result = remove_consecutive_duplicates(string);
        printf("Test 3\n");
        printf("Expected:ab 2\n");
        printf("Actual  :%s %d\n", string, result);
        printf("\n");
    }

    {
        char string[] = "bbbbbba";
        int result = remove_consecutive_duplicates(string);
        printf("Test 4\n");
        printf("Expected:ba 2\n");
        printf("Actual  :%s %d\n", string, result);
        printf("\n");
    }
    
    {
        char string[] = "a";
        int result = remove_consecutive_duplicates(string);
        printf("Test 5\n");
        printf("Expected:a 1\n");
        printf("Actual  :%s %d\n", string, result);
        printf("\n");
    }

    {
        char string[] = "";
        int result = remove_consecutive_duplicates(string);
        printf("Test 6\n");
        printf("Expected:>< 0\n");
        printf("Actual  :>%s< %d\n", string, result);
        printf("\n");
    }
}