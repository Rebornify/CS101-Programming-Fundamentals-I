// Note: You are NOT allowed to edit this file
#include <stdbool.h>
#include <stdio.h>
#include "q5answer.h"

bool is_leap_year(int year) {
    return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}

int get_days_in_month(int month) {
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }

    if (month == 2) {
        return 28;
    }

    return 31;
}

int num_days_since_epoch(int day, int month, int year) {
    int num_leap_years = 0;
    for (int i = 1970; i < year; i ++) {
        if (is_leap_year(i)) {
            num_leap_years++;
        }
    }

    if (is_leap_year(year) && month > 2) {
        num_leap_years++;
    }

    int num_days = (year - 1970) * 365 + num_leap_years;

    for (int i = 0; i < month; i++) {
        num_days += get_days_in_month(i);
    }

    return num_days + day - 1;
}

int num_days_between(int d1, int m1, int y1, int d2, int m2, int y2) {
    int num_days1 = num_days_since_epoch(d1, m1, y1);
    int num_days2 = num_days_since_epoch(d2, m2, y2);

    return num_days1 - num_days2;
}

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