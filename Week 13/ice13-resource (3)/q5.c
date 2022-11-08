#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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