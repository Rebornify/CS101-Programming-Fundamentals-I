#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_immediate_hashtag(char *str) {
    char *result = calloc(sizeof(char), 100);
    char *ptr = result;

    // copy the # character over
    *ptr = *str;
    str++;
    ptr++;

    bool is_letter = false;
    while (*str != '\0' && (isalnum(*str) || *str == '_')) {
        if (isalpha(*str)) {
            is_letter = true;
        }
        *ptr = *str;

        ptr++;
        str++;
    }

    if (!is_letter) {
        result[1] = '\0';
    }
    
    if (strlen(result) == 1) {
        free(result);
        result = NULL;
    } else {
        result = realloc(result, strlen(result) + 1);
    }
    return result;
}

char **get_hashtags(char *sentence, int *n) {
    char **result = calloc(strlen(sentence), sizeof(char*));
    int result_idx = 0;

    while (*sentence != '\0') {
        if (*sentence == '#') {
            char *hashtag = get_immediate_hashtag(sentence);
            if (hashtag != NULL) {
                result[result_idx++] = hashtag;
                sentence += strlen(hashtag);
            } else {
                sentence++;
            }
        } else {
            sentence++;
        }
    }
    *n = result_idx;

    // printf("%d <-- \n", result_idx);
    if (result_idx == 0) {
        free(result);
        result = NULL;
    } else {
        result = realloc(result, result_idx * sizeof(char*));
    }
    return result;
}
int main(void) {
    int tc_num = 1;
    {
        printf("Test %d  :get_hashtags(\"You #jump I jump\")\n", tc_num++);
        printf("Expected:#jump\n");
        printf("Actual  :");
        int n;
        char **result = get_hashtags("You #jump I leap", &n);
        for (int i = 0; i < n; i++) {
            printf("%s ", result[i]);
            free(result[i]);
        }
        free(result);
        printf("\n");
        printf("\n");
    }

    {
        printf("Test %d  :get_hashtags(\"There is no hashtag\")\n", tc_num++);
        printf("Expected:0 true\n");
        int n;
        char **result = get_hashtags("There is no hashtag", &n);
        printf("Actual  :%d %s", n, result == NULL ? "true" : "false");
        printf("\n");
        printf("\n");
    }

    {
        printf("Test %d  :get_hashtags(\"#tag1-#tag2-#tag3-#tag4\")\n", tc_num++);
        printf("Expected:#tag1 #tag2 #tag3 #tag4\n");
        int n;
        char **result = get_hashtags("#tag1-#tag2-#tag3-#tag4", &n);
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%s ", result[i]);
            free(result[i]);
        }
        free(result);
        printf("\n");
        printf("\n");
    }

    {
        printf("Test %d  :get_hashtags(\"#War&Peace #WarAndPeace.\")\n", tc_num++);
        printf("Expected:#War #WarAndPeace\n");
        int n;
        char **result = get_hashtags("#War&Peace #WarAndPeace.", &n);
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%s ", result[i]);
            free(result[i]);
        }
        free(result);
        printf("\n");
        printf("\n");
    }

    {
        printf("Test %d  :get_hashtags(\"#12##34#1for1#COVID\")\n", tc_num++);
        printf("Expected:#1for1 #COVID\n");
        int n;
        char **result = get_hashtags("#12##34#1for1#COVID", &n);
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%s ", result[i]);
            free(result[i]);
        }
        free(result);
        printf("\n");
        printf("\n");
    }

{
    int n;
char **result = get_hashtags("#13 ## #War&Peace #WarAndPeace.", &n);
for (int i = 0; i < n; i++) {
    printf("%s ", result[i]);
    free(result[i]);
}
free(result);

}
}