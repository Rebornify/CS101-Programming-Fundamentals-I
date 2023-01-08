// Name :
// Email:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stutter(char word[], int n, char sep[]) {
    int word_len = strlen(word);
    int sep_len = strlen(sep);
    
    char *answer = calloc(word_len * (n + sep_len) + 1, sizeof(char));
    char *word_temp = answer;

    for (int i = 0; i < word_len - 1; i++) {
        for (int j = 0; j < n; j++) {
            *word_temp++ = *word;
        }

        char *sep_temp = sep;
        
        for (int k = 0; k < sep_len; k++){
            *word_temp++ = *sep_temp++;
        }

        word++;
    }

    for (int j = 0; j < n; j++) {
        *word_temp++ = *word;
    }

    return answer;
}

// DO NOT MODIFY THE CODE BELOW!

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

    // {
    //     char *answer = stutter("happy", 2, "|");
    //     printf("Test Case %d\n", tc_num++);
    //     printf("Expected:hh|aa|pp|pp|yy\n");
    //     printf("Actual  :%s\n", answer);
    //     printf("\n");
    //     free(answer);
    // }

    // {
    //     char *answer = stutter("happy", 3, "**");
    //     printf("Test Case %d\n", tc_num++);
    //     printf("Expected:hhh**aaa**ppp**ppp**yyy\n");
    //     printf("Actual  :%s\n", answer);
    //     printf("\n");
    //     free(answer);
    // }

    // {
    //     char *answer = stutter("A", 5, "[###]");
    //     printf("Test Case %d\n", tc_num++);
    //     printf("Expected:AAAAA\n");
    //     printf("Actual  :%s\n", answer);
    //     printf("\n");
    //     free(answer);
    // }

    // {
    //     char *answer = stutter("", 2, "%%%%%");
    //     printf("Test Case %d\n", tc_num++);
    //     printf("Expected:[]\n");
    //     printf("Actual  :[%s]\n", answer);
    //     printf("\n");
    //     free(answer);
    // }
}