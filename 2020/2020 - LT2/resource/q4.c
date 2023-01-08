// Name :
// Email:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *get_replacement(char template[], char *variables[], int num_variables) {
    for (int i = 0; i < num_variables; i += 2) {
        if (strcmp(variables[i], template) == 0) {
            return variables[i + 1];
        }
    }
    return NULL;
}

int get_required_length(char template[], char *variables[], int num_variables) {
    int total = 0;

    for (int i = 0; i < num_variables; i += 2) {
        char *var = variables[i];

        char var_name[strlen(var) + 3 ];
        strcpy(var_name, "{");
        strcat(var_name, var);
        strcat(var_name, "}");

        int n = strlen(var_name);
        int count = 0;

        char *ptr = strstr(template, var_name);
        while (ptr != NULL) {
            count++;
            ptr += n;
            ptr = strstr(ptr, var_name);
        }

        total += count * (int)sizeof(char) * ((int)strlen(variables[i + 1]) - n);
    }

    return total;
}

char *merge(char template[], char *variables[], int num_variables) {
    int required = get_required_length(template, variables, num_variables);
    char *result = calloc((int)strlen(template) + required + 1, sizeof(char));

    char *ptr = template;
    char *start = template;

    int n = 0;
    while (*ptr != '\0') {
        if (*ptr == '{') {
            strncat(result, start, n);

            char *var_start = ++ptr;

            int word_len = 0;

            while (*ptr != '}') {
                word_len++;
                ptr++;
            }

            char word[word_len + 1];
            strncpy(word, var_start, word_len);
            word[word_len] = '\0';

            char *value = get_replacement(word, variables, num_variables);
            strcat(result, value);

            start = ++ptr;
            n = 0;
        } else {
            n++;
            ptr++;
        }
    }

    return result;
}

// DO NOT MODIFY THE CODE BELOW!

int main(void) {
    int tc_num = 1;
    {
        char *variables[] = {"var1", "apple", "var2", "orange"};
        char *result = merge("{var1}-{var2}", variables, sizeof(variables)/sizeof(char *));
        printf("Test Case %d\n", tc_num++);
        printf("Expected:apple-orange\n");
        printf("Actual  :%s\n", result);
        free(result);
        printf("\n");
    }
    
    {
        char *variables[] = {"var1", "apple", "var2", "orange"};
        char *result = merge("{var1}{var2}{var1}{var2}", variables, sizeof(variables)/sizeof(char *));
        printf("Test Case %d\n", tc_num++);
        printf("Expected:appleorangeappleorange\n");
        printf("Actual  :%s\n", result);
        free(result);
        printf("\n");
    }

    {
        char *variables[] = {"name", "apple", "temperature", "37.5"};
        char *result = merge("Good morning, {name}! Your temperature is {temperature}", variables, sizeof(variables)/sizeof(char *));
        printf("Test Case %d\n", tc_num++);
        printf("Expected:Good morning, apple! Your temperature is 37.5\n");
        printf("Actual  :%s\n", result);
        free(result);
        printf("\n");
    }
}
