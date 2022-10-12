#include <stdio.h>
#include <stdbool.h>



int main(void) {
    {
        char *haystack = "this is a simple string";
        char *needle = "simple";
        printf("Test 1\n");
        printf("Expected:simple string\n");
        printf("Actual  :%s\n", my_strstr(haystack, needle));
        printf("\n");
    }

    {
        char *haystack = "this is a simple string";
        char *needle = "";
        printf("Test 2\n");
        printf("Expected:this is a simple string\n");
        printf("Actual  :%s\n", my_strstr(haystack, needle));
        printf("\n");
    }

    {
        char *haystack = "C is a wonderful language";
        char *needle = "Python";
        printf("Test 3\n");
        printf("Expected:(null)\n");
        printf("Actual  :%s\n", my_strstr(haystack, needle));
        printf("\n");
    }

    {
        char *haystack = "apples and oranges";
        char *needle = "apple";
        printf("Test 4\n");
        printf("Expected:apples and oranges\n");
        printf("Actual  :%s\n", my_strstr(haystack, needle));
        printf("\n");
    }

    {
        char *haystack = "apples and oranges";
        char *needle = "orange";
        printf("Test 5\n");
        printf("Expected:oranges\n");
        printf("Actual  :%s\n", my_strstr(haystack, needle));
        printf("\n");
    }

    {
        char *haystack = "apples and orange";
        char *needle = "orangest";
        printf("Test 6\n");
        printf("Expected:(null)\n");
        printf("Actual  :%s\n", my_strstr(haystack, needle));
        printf("\n");
    }

}