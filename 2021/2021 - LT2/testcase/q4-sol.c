#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TC1 1
#define TC2 1
#define TC3 1
#define TC4 1
#define TC5 1

#if SINGLE_TC == 1
#define TC1 1
#define TC2 0
#define TC3 0
#define TC4 0
#define TC5 0
#endif

#if SINGLE_TC == 2
#define TC1 0
#define TC2 1
#define TC3 0
#define TC4 0
#define TC5 0
#endif

#if SINGLE_TC == 3
#define TC1 0
#define TC2 0
#define TC3 1
#define TC4 0
#define TC5 0
#endif

#if SINGLE_TC == 4
#define TC1 0
#define TC2 0
#define TC3 0
#define TC4 1
#define TC5 0
#endif

#if SINGLE_TC == 5
#define TC1 0
#define TC2 0
#define TC3 0
#define TC4 0
#define TC5 1
#endif

char *get_immediate_hashtag__(char *str) {
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

char **expected_get_hashtags(char *sentence, int *n) {
    char **result = calloc(strlen(sentence), sizeof(char*));
    int result_idx = 0;

    while (*sentence != '\0') {
        if (*sentence == '#') {
            char *hashtag = get_immediate_hashtag__(sentence);
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
    if (0) {
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

    if (0) {
        printf("Test %d  :get_hashtags(\"There is no hashtag\")\n", tc_num++);
        printf("Expected:0 true\n");
        int n;
        char **result = get_hashtags("There is no hashtag", &n);
        printf("Actual  :%d %s", n, result == NULL ? "true" : "false");
        printf("\n");
        printf("\n");
    }

    if (0) {
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

    if (0) {
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

    if (0) {
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

if (0) {
    int n;
char **result = get_hashtags("#13 ## #War&Peace #WarAndPeace.", &n);
for (int i = 0; i < n; i++) {
    printf("%s ", result[i]);
    free(result[i]);
}
free(result);

}


    /***   Secret test cases   ***/

    if (TC1) {
        tc_num = 1;
        double score = 1;
        char* input = "###UwU###";

        printf("Test %d  : get_hashtags(%s)\n", tc_num, input);

        int expected_n = 0;
        char **expected_result = expected_get_hashtags(input, &expected_n);
        printf("Expected: ");
        for (int i = 0; i < expected_n; i++) {
            printf("%s ", expected_result[i]);
        }
        printf("\n");

        int actual_n = 0;
        char **actual_result = get_hashtags(input, &actual_n);
        printf("Actual:   ");
        for (int i = 0; i < actual_n; i++) {
            printf("%s ", actual_result[i]);
        }

        if (expected_n != actual_n) {
            score = 0;
        } else {
            for (int i = 0; i < actual_n; i++) {
                if (strcmp(expected_result[i], actual_result[i]) != 0) {
                    score = 0;
                }
            }            
        }
        printf("\n");
        printf("%s,%d,%.2f\n\n", __FILE__, tc_num, score);

        // Free
        for (int i = 0; i < expected_n; i++) {
            free(expected_result[i]);
        }
        free(expected_result);
        for (int i = 0; i < actual_n; i++) {
            free(actual_result[i]);
        }
        free(actual_result);

    }

    if (TC2) {
        tc_num = 2;
        double score = 1;
        char* input = "# ## ### #### #####";

        printf("Test %d  : get_hashtags(%s)\n", tc_num, input);

        int expected_n = 0;
        char **expected_result = expected_get_hashtags(input, &expected_n);
        printf("Expected: ");
        for (int i = 0; i < expected_n; i++) {
            printf("%s ", expected_result[i]);
        }
        printf("\n");

        int actual_n = 0;
        char **actual_result = get_hashtags(input, &actual_n);
        printf("Actual:   ");
        for (int i = 0; i < actual_n; i++) {
            printf("%s ", actual_result[i]);
        }

        if (expected_n != actual_n) {
            score = 0;
        } else {
            for (int i = 0; i < actual_n; i++) {
                if (strcmp(expected_result[i], actual_result[i]) != 0) {
                    score = 0;
                }
            }            
        }
        printf("\n");
        printf("%s,%d,%.2f\n\n", __FILE__, tc_num, score);

        // Free
        for (int i = 0; i < expected_n; i++) {
            free(expected_result[i]);
        }
        free(expected_result);
        for (int i = 0; i < actual_n; i++) {
            free(actual_result[i]);
        }
        free(actual_result);

    }

    if (TC3) {
        tc_num = 2;
        double score = 1;
        char* input = "#0 #1_ #_";

        printf("Test %d  : get_hashtags(%s)\n", tc_num, input);

        int expected_n = 0;
        char **expected_result = expected_get_hashtags(input, &expected_n);
        printf("Expected: ");
        for (int i = 0; i < expected_n; i++) {
            printf("%s ", expected_result[i]);
        }
        printf("\n");

        int actual_n = 0;
        char **actual_result = get_hashtags(input, &actual_n);
        printf("Actual:   ");
        for (int i = 0; i < actual_n; i++) {
            printf("%s ", actual_result[i]);
        }

        if (expected_n != actual_n) {
            score = 0;
        } else {
            for (int i = 0; i < actual_n; i++) {
                if (strcmp(expected_result[i], actual_result[i]) != 0) {
                    score = 0;
                }
            }            
        }
        printf("\n");
        printf("%s,%d,%.2f\n\n", __FILE__, tc_num, score);

        // Free
        for (int i = 0; i < expected_n; i++) {
            free(expected_result[i]);
        }
        free(expected_result);
        for (int i = 0; i < actual_n; i++) {
            free(actual_result[i]);
        }
        free(actual_result);

    }


    if (TC4) {
        tc_num = 4;
        double score = 1;
        char* input = "#0#_#a #a #0 #_";

        printf("Test %d  : get_hashtags(%s)\n", tc_num, input);

        int expected_n = 0;
        char **expected_result = expected_get_hashtags(input, &expected_n);
        printf("Expected: ");
        for (int i = 0; i < expected_n; i++) {
            printf("%s ", expected_result[i]);
        }
        printf("\n");

        int actual_n = 0;
        char **actual_result = get_hashtags(input, &actual_n);
        printf("Actual:   ");
        for (int i = 0; i < actual_n; i++) {
            printf("%s ", actual_result[i]);
        }

        if (expected_n != actual_n) {
            score = 0;
        } else {
            for (int i = 0; i < actual_n; i++) {
                if (strcmp(expected_result[i], actual_result[i]) != 0) {
                    score = 0;
                }
            }            
        }
        printf("\n");
        printf("%s,%d,%.2f\n\n", __FILE__, tc_num, score);

        // Free
        for (int i = 0; i < expected_n; i++) {
            free(expected_result[i]);
        }
        free(expected_result);
        for (int i = 0; i < actual_n; i++) {
            free(actual_result[i]);
        }
        free(actual_result);

    }

}