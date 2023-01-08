#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *get_email(char *sentence) {
    char *temp = sentence;

    bool is_email = false;

    while (!is_email) {
        while (*temp != '\0' && *temp != ' ') {
            if (*temp == '@') { 
                is_email = true;
            }
            temp++;
        }

        if (*temp != '\0' && !is_email) { 
            sentence = temp + 1;
            temp = sentence;
        } else {
            break;
        }
    }

    int len = strlen(sentence) - strlen(temp);
    char *result = calloc(len + 1, sizeof(char));

    strncpy(result, sentence, len);

    return result;
}

int main(void) {
    {
        char *result = get_email("my email is apple@gmail.com do keep in touch");
        printf("Expected:[apple@gmail.com]\n");
        printf("Actual  :[%s]\n", result);
        free(result);
        printf("\n");
    }

    {
        char *result = get_email("apple@gmail.com is my email");
        printf("Expected:[apple@gmail.com]\n");
        printf("Actual  :[%s]\n", result);
        free(result);
        printf("\n");
    }

    {
        char *result = get_email("My email is orange@smu.edu.sg");
        printf("Expected:[orange@smu.edu.sg]\n");
        printf("Actual  :[%s]\n", result);
        free(result);
        printf("\n");
    }
}
