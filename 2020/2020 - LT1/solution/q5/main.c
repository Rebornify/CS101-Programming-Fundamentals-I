// Note: You are NOT allowed to edit this file
#include <stdbool.h>
#include <stdio.h>
#include "q5answer.h"

int main(void) {
    int tc_num = 1;
    {
        printf("Test %d\n", tc_num++);
        printf("Expected:31\n");
        printf("Actual  :%d\n", num_days_between(1, 2, 1970, 1, 1, 1970));
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        printf("Expected:-8084\n");
        printf("Actual  :%d\n", num_days_between(8, 8, 1998, 25, 9, 2020));
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        printf("Expected:0\n");
        printf("Actual  :%d\n", num_days_between(25, 9, 2020, 25, 9, 2020));
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        printf("Expected:56\n");
        printf("Actual  :%d\n", num_days_between(1, 3, 2000, 5, 1, 2000));
        printf("\n");
    }
}