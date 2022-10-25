#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stutter(char word[], int n, char sep[]) {
    int word_len = strlen(word);
    int sep_len = strlen(sep);

    if (word_len == 0) {
        return calloc(1, sizeof(char));
    }
    int len = sizeof(char) * (1 + word_len * n + sep_len * (word_len - 1));
    char *result = calloc(len, sizeof(char));
    char *ptr = result;

    // apply fence-post. copy the character n times first
    for (int i = 0; i < n; i++) {
        *ptr = *word;
        ptr++;
    }

    word++;

    while (*word != '\0') {
        // copy the separator
        strncat(result, sep, sep_len);
        ptr += sep_len;

        // copy the character n times
        for (int i = 0; i < n; i++) {
            *ptr = *word;
            ptr++;
        }

        word++;
    }

    return result;
}
int main(void) {

    int tc_num = 1;
    {
        char *answer = stutter("abc", 1, "#");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:a#b#c\n");
        printf("Actual  :%s\n", answer);
        printf("\n");
        free(answer);
    }

    {
        char *answer = stutter("happy", 5, "");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:hhhhhaaaaappppppppppyyyyy\n");
        printf("Actual  :%s\n", answer);
        printf("\n");
        free(answer);
    }

    {
        char *answer = stutter("happy", 2, "|");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:hh|aa|pp|pp|yy\n");
        printf("Actual  :%s\n", answer);
        printf("\n");
        free(answer);
    }

    {
        char *answer = stutter("happy", 3, "**");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:hhh**aaa**ppp**ppp**yyy\n");
        printf("Actual  :%s\n", answer);
        printf("\n");
        free(answer);
    }

    {
        char *answer = stutter("A", 5, "[###]");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:AAAAA\n");
        printf("Actual  :%s\n", answer);
        printf("\n");
        free(answer);
    }

    {
        char *answer = stutter("", 2, "%%%%%");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:[]\n");
        printf("Actual  :[%s]\n", answer);
        printf("\n");
        free(answer);
    }
}