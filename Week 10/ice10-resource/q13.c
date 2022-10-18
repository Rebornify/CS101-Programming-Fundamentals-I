#include <stdio.h>

int main(void) {
    {
        char *s1 = "happy";
        char *s2 = "happen";
        char s3[10];
        longest_common_prefix(s1, s2, s3);
        printf("Test 1\n");
        printf("Expected:happ\n");
        printf("Actual  :%s\n", s3);
        printf("\n");
    }

    {
        char *s1 = "manual";
        char *s2 = "man";
        char s3[10];
        longest_common_prefix(s1, s2, s3);
        printf("Test 2\n");
        printf("Expected:man\n");
        printf("Actual  :%s\n", s3);
        printf("\n");
    }

    {
        char *s1 = "good";
        char *s2 = "food";
        char s3[10];
        longest_common_prefix(s1, s2, s3);
        printf("Test 3\n");
        printf("Expected:><\n");
        printf("Actual  :>%s<\n", s3);
        printf("\n");
    }

    {
        char *s1 = "good";
        char *s2 = "goodie";
        char s3[10];
        longest_common_prefix(s1, s2, s3);
        printf("Test 4\n");
        printf("Expected:good\n");
        printf("Actual  :%s\n", s3);
        printf("\n");
    }
}