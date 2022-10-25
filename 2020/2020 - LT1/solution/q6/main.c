/*
You must NOT modify this file.
*/

#include <stdio.h>
#include "q6answer.h"

int main(void) {
    int tc_num = 1;
    {
        int timings[] = {
            600, 700,
            700, 800,
            800, 900};

        int result = get_crowd_size(timings, sizeof(timings) / sizeof(int));
        printf("Test %d\n", tc_num++);
        printf("Expected:1\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        int timings[] = {600, 900,
                         700, 900,
                         800, 900};

        int result = get_crowd_size(timings, sizeof(timings) / sizeof(int));
        printf("Test %d\n", tc_num++);
        printf("Expected:3\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

        {
        int timings[] = {
            600, 1300,
            700, 1400,
            1400, 1500,
            1400, 1600,
            1700, 2200};

        int result = get_crowd_size(timings, sizeof(timings) / sizeof(int));
        printf("Test %d\n", tc_num++);
        printf("Expected:2\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

        {
        int timings[] = {
            600, 900,
            700, 800,
            730, 830,
            800, 1200};

        int result = get_crowd_size(timings, sizeof(timings) / sizeof(int));
        printf("Test %d\n", tc_num++);
        printf("Expected:3\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}
