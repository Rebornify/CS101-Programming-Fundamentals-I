#include <stdio.h>
#include <string.h>

int get_len(char *s1, char *s2) {
    int len1 = 0;
    while (*s1 != '\0') {
        len1++;
        s1++;
    }

    int len2 = 0;
    while (*s2 != '\0') {
        len2++;
        s2++;
    }

    return len1 < len2 ? len1 : len2;
}

void longest_common_suffix(char *s1, char *s2, char *s3) {
    int len = get_len(s1, s2);

    while (*s1!= '\0') {
        s1++;
    }

    while (*s2 != '\0') {
        s2++;
    }

    int suffix_len = 0;
    while (suffix_len < len) {
        if (*(s1 - 1) == *(s2 - 1)) {
            s1--;
            s2--;
            suffix_len++;
        } else {
            break;
        }
    }

    while (*s1 != '\0') {
        *s3++ = *s1++;
    }
    
    *s3 = '\0';
}

int main(void) {
    {
        char *s1 = "incident";
        char *s2 = "accident";
        char s3[20];
        longest_common_suffix(s1, s2, s3);
        printf("Test 1\n");
        printf("Expected:cident\n");
        printf("Actual  :%s\n", s3);
        printf("\n");
    }

    {
        char *s1 = "crocodile";
        char *s2 = "horse";
        char s3[20];
        longest_common_suffix(s1, s2, s3);
        printf("Test 2\n");
        printf("Expected:e\n");
        printf("Actual  :%s\n", s3);
        printf("\n");
    }

    {
        char *s1 = "eat";
        char *s2 = "treat";
        char s3[20];
        longest_common_suffix(s1, s2, s3);
        printf("Test 3\n");
        printf("Expected:eat\n");
        printf("Actual  :%s\n", s3);
        printf("\n");
    }

    {
        char *s1 = "discontent";
        char *s2 = "discontinue";
        char s3[20];
        longest_common_suffix(s1, s2, s3);
        printf("Test 4\n");
        printf("Expected:><\n");
        printf("Actual  :>%s<\n", s3);
        printf("\n");
    }
}