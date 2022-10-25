/*
    Name:
    Email:

*/

#include <stdio.h>
#include <math.h>

// write your answer below
int extract(int num, int start, int end) {
    int num_digits = (num == 0) ? 1 : (log10(num) + 1);

    int new_end = end < num_digits ? end : num_digits;

    int result = 0;
    for (int i = start; i < new_end; i++) {
        int n = num_digits - i - 1;
        result = result * 10 + num / (int)pow(10, n) % 10;
    }
    return result;
}

// do not edit the main method.

int main(void) {
    int tc_num = 1;

    {
        printf("Test %d\n", tc_num++);
        int x = 123456;
        int result = extract(x, 1, 3);
        printf("Expected:23\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        int x = 374512;
        int result = extract(x, 3, 4);
        printf("Expected:5\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        int x = 374512;
        int result = extract(x, 3, 8);
        printf("Expected:512\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        int x = 1;
        int result = extract(x, 0, 1);
        printf("Expected:1\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        int x = 11;
        int result = extract(x, 0, 1);
        printf("Expected:1\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}