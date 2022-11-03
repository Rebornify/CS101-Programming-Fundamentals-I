#include <stdio.h>
#include <string.h>

char *get_longest_word(char *word_array[], int n) {
    char *longest_word = word_array[0];
    int longest_word_len = strlen(word_array[0]);

    for (int i = 1; i < n; i++) {
        int len = strlen(word_array[i]);
        if (len > longest_word_len) {
            longest_word = word_array[i];
            longest_word_len = len;
        }
    }
    return longest_word;
}

int main(void) {
    int tc_num = 1;
    {
        printf("Test Case %d\n", tc_num++);
        char *word[] = {"apple", "nut", "coconut"};
        printf("Expected:coconut\n");
        printf("Actual  :%s\n", get_longest_word(word, sizeof(word)/sizeof(char *)));
        printf("\n");
    }

    {
        printf("Test Case %d\n", tc_num++);
        char *word[] = {"coconut"};
        printf("Expected:coconut\n");
        printf("Actual  :%s\n", get_longest_word(word, sizeof(word)/sizeof(char *)));
        printf("\n");
    }

    {
        printf("Test Case %d\n", tc_num++);
        char *word[] = {""};
        printf("Expected:[]\n");
        printf("Actual  :[%s]\n", get_longest_word(word, sizeof(word)/sizeof(char *)));
        printf("\n");
    }
}