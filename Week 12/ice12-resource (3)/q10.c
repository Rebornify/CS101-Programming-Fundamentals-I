#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int count_names_with_space(char *names[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        char *temp = names[i];

        int len = strlen(temp);

        for (int j = 0; j < len; j++) {
            if (temp[j] == ' ') {
                count++;
                break;
            }
        }
    }
    return count;
}

int main(void) {
    int tc_num = 1;
    {
        char *names[] = {"George W. Bush", "George Washington", "Bill", "Gates", "Bill Gates"};
        int result = count_names_with_space(names, sizeof(names) / sizeof(char *));
        printf("Test Case %d\n", tc_num++);
        printf("Expected:3\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        char *names[] = {"TAN Ah Lian", "Bill", "Gates", "Bill Gates"};
        int result = count_names_with_space(names, sizeof(names) / sizeof(char *));
        printf("Test Case %d\n", tc_num++);
        printf("Expected:2\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        char *names[] = {"Alvin", "Bill", "Cody", "Don", "Elf"};
        int result = count_names_with_space(names, sizeof(names) / sizeof(char *));
        printf("Test Case %d\n", tc_num++);
        printf("Expected:0\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        char *names[] = {"Alvin"};
        int result = count_names_with_space(names, sizeof(names) / sizeof(char *));
        printf("Test Case %d\n", tc_num++);
        printf("Expected:0\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}