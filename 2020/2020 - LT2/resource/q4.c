// Name :
// Email:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char * merge(char template[], char *variables[], int n) {
    return NULL;
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
