#include <stdio.h>
#include <string.h>

void reverse_words(char str[]) {
    int len = strlen(str);
    if (len == 0) {
        return;
    }

    char reversed[len];
    int index = 0;

    int word_start = len - 1;
    int word_end = len - 1;
    
    int i;
    while (word_start > 0) {
        if (str[word_start] == ' ') {
            i = word_start + 1;
            while (i <= word_end) {
                reversed[index++] = str[i++];
            }
            reversed[index++] = ' ';

            word_end = word_start - 1;
        }
        word_start--;
    }

    for (int i = 0; i <= word_end; i++) {
        reversed[index++] = str[i];
    }

    for (int i = 0; i < len; i++) {
        str[i] = reversed[i];
    }
}

int main(void) {
    {
        printf("Test 1\n");
        char sentence[] = "apple and orange";
        reverse_words(sentence);
        printf("Expected:orange and apple\n");
        printf("Actual  :%s\n", sentence);
        printf("\n");
    }

    {
        printf("Test 2\n");
        char sentence[] = "I sell seashell by the seashore";
        reverse_words(sentence);
        printf("Expected:seashore the by seashell sell I\n");
        printf("Actual  :%s\n", sentence);
        printf("\n");
    }

    {
        printf("Test 3\n");
        char sentence[] = "I";
        reverse_words(sentence);
        printf("Expected:I\n");
        printf("Actual  :%s\n", sentence);
        printf("\n");
    }

    {
        printf("Test 4\n");
        char sentence[] = "";
        reverse_words(sentence);
        printf("Expected:><\n");
        printf("Actual  :>%s<\n", sentence);
        printf("\n");
    }
}
