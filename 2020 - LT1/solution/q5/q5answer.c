#include <stdbool.h>
#include <stdio.h>

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

int num_days_since_epoch(int day1, int mth1, int yr1) {
    int num_leap_years = 0;
    for (int i = 1970; i < yr1; i++) {
        if (is_leap_year(i)) {
            num_leap_years += 1;
        }
    }

    if (is_leap_year(yr1) && mth1 > 2) {
        num_leap_years += 1;
    }

    int num_days = (yr1 - 1970) * 365 + num_leap_years;

    for (int i = 1; i < mth1; i++) {
        num_days += get_days_in_month(i);
    }
    return num_days + day1 - 1;
}

int num_days_between(int d1, int m1, int y1, int d2, int m2, int y2) {
    int num_days1 = num_days_since_epoch(d1, m1, y1);
    int num_days2 = num_days_since_epoch(d2, m2, y2);
    
    return num_days1 - num_days2;
}