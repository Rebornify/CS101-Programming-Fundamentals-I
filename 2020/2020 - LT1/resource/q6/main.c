/*
You must NOT modify this file.
*/

#include <stdio.h>
#include "q6answer.h"

void bubble_sort(int values[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (values[j] > values[j + 1]) {
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
}

int get_crowd_size(int timings[], int n) {
    int entries[n /2];
    int exits[n / 2];

    for (int i = 0; i < n; i += 2) {
        entries[i / 2] = timings[i];
        exits[i / 2] = timings[i + 1];
    }

    bubble_sort(entries, n / 2);
    bubble_sort(exits, n / 2);

    int highest = 0;
    int count = 0;

    int entries_pos = 0;
    int exits_pos = 0;

    while(entries_pos < n / 2 && exits_pos < n / 2) {
        if (entries[entries_pos] < exits[exits_pos]) {
            count++;
            entries_pos++;
        } else {
            count--;
            exits_pos++;
        }

        if (count > highest) {
            highest = count;
        }
    }

    return highest;
}

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
