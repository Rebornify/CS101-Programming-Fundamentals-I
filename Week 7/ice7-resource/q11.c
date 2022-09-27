#include <stdio.h>
#include <string.h>


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
