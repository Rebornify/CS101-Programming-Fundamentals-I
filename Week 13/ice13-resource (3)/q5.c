#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_balanced(char *input) {
    int input_len = strlen(input);
    if (input_len == 0) {
        return true;
    }

    char stack[input_len];
    stack[0] = '\0';
    int stack_idx = 1;

    for (int i = 0; i < input_len; i++) {
        if (input[i] == ' ') {
            
        } else if (input[i] == '{' || input[i] == '[' || input[i] == '(') {
            stack[stack_idx++] = input[i];
        } else if (input[i] == '}' && stack[stack_idx - 1] != '{') {
            return false;
        } else if (input[i] == ']' && stack[stack_idx - 1] != '[') {
            return false;
        } else if (input[i] == ')' && stack[stack_idx - 1] != '(') {
            return false;
        } else {
            stack_idx--;
        }
    }

    return true;
}

int main(void) {
    int count = 1;
    {
        char *input = "{[()]}";
        printf("Test %d:\n", count++);
        printf("Expected:true\n");
        printf("Actual  :%s\n", is_balanced(input) ? "true" : "false");
        printf("\n");
    }

    {
        char *input = "{[(])}";
        printf("Test %d:\n", count++);
        printf("Expected:false\n");
        printf("Actual  :%s\n", is_balanced(input) ? "true" : "false");
        printf("\n");
    }

    {
        char *input = "{}[](((((())))))";
        printf("Test %d:\n", count++);
        printf("Expected:true\n");
        printf("Actual  :%s\n", is_balanced(input) ? "true" : "false");
        printf("\n");
    }

    {
        char *input = "{{}[]()}{[][]}";
        printf("Test %d:\n", count++);
        printf("Expected:true\n");
        printf("Actual  :%s\n", is_balanced(input) ? "true" : "false");
        printf("\n");
    }

    {
        char *input = "{{}[[{}]]()}{}[]";
        printf("Test %d:\n", count++);
        printf("Expected:true\n");
        printf("Actual  :%s\n", is_balanced(input) ? "true" : "false");
        printf("\n");
    }

    {
        char *input = "";
        printf("Test %d:\n", count++);
        printf("Expected:true\n");
        printf("Actual  :%s\n", is_balanced(input) ? "true" : "false");
        printf("\n");
    }

    {
        char *input = "{}{}{}}";
        printf("Test %d:\n", count++);
        printf("Expected:false\n");
        printf("Actual  :%s\n", is_balanced(input) ? "true" : "false");
        printf("\n");
    }

    {
        char *input = "{{{{{}}}}} {}{}}";
        printf("Test %d:\n", count++);
        printf("Expected:false\n");
        printf("Actual  :%s\n", is_balanced(input) ? "true" : "false");
        printf("\n");
    }
}