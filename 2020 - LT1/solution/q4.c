 /*
    Name:
    Email:

*/

#include <stdio.h>
#include <stdbool.h>

// write your answer below
bool is_infinite_number(int num) {
    while (num != 1 && num != 4) {
        int next_num = 0;
        while (num != 0) {
            int digit = num % 10;
            next_num += digit * digit;

            num /= 10;
        }
        num = next_num;
    }
    return num == 4;
}

// do not edit the main method.

int main(void) {
    int tc_num = 1;

    {
        printf("Test %d\n", tc_num++);
        bool result = is_infinite_number(1);
        printf("Expected:false\n");
        printf("Actual  :%s\n", result ? "true" : "false");
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        bool result = is_infinite_number(2);
        printf("Expected:true\n");
        printf("Actual  :%s\n", result ? "true" : "false");
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        bool result = is_infinite_number(144);
        printf("Expected:true\n");
        printf("Actual  :%s\n", result ? "true" : "false");
        printf("\n");
    }
}