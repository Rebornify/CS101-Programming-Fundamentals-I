#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char * get_replacement(char *template, char *variables[], int num_variables) {
    for (int i = 0; i < num_variables; i += 2) {
        if (strcmp(variables[i],template) == 0) {
            // printf("went in ..\n");
            return variables[i+1];
        }
    }
    printf("returning null \n");
    return NULL;
}

int get_required_length(char *template, char *variables[], int num_variables) {
    int total = 0;
    for (int i = 0; i < num_variables; i+=2) {
        char *var = variables[i];
        char var_name[strlen(var) + 3];
        strcpy(var_name, "{");
        strcat(var_name, var);
        strcat(var_name, "}");
        // printf("%s\n", template);
        

        int count = 0;
        int n = strlen(var_name);
        char *ptr = strstr(template, var_name);
        while (ptr != NULL) {
            ptr += n;
            count++;
            ptr = strstr(ptr, var_name);
        }
        total += count * (int)sizeof(char) * ((int)strlen(variables[i+1]) - (int)strlen(var_name));
        // printf("%d %lu %lu\n", count, strlen(variables[i+1]), strlen(template));
        // printf("--\n");
    }
    return (int)total;

}
char * merge(char template[], char *variables[], int num_variables) {
    int required = get_required_length(template, variables, num_variables);
    char *result = calloc((int)strlen(template) + required, sizeof(char) + 1);

    char *ptr = template;
    char *start = template;

    int n = 0;
    while (*ptr != '\0') {
        if (*ptr == '{') {
            // copy everything in front
            // printf("%s\n", start);
            strncat(result, start, n);

            int word_len = 0;
            char *var_start = ++ptr;
            while (*ptr != '}') {
                word_len++;
                ptr++;
            }

            // extract the variable
            char word[word_len+1];
            strncpy(word, var_start, word_len);
            word[word_len] = '\0';

            char *value = get_replacement(word, variables, num_variables);
            strcat(result, value);
            // printf("%s\n", word);

            start = ++ptr;
            n = 0;
        } else {
            n++;
            ptr++;
        }
    }
    return result;

}


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
