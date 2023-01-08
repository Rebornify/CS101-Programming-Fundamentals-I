#include <stdbool.h>
#include <stdio.h>

const int min_charges[] =  {0, 12, 15, 12, 15, 12, 18, 18};
const double hourly_charges[] = {0, 2, 2.5, 2, 2.5, 2, 3, 3};
const int max_charges[] = {0, 30, 35, 30, 35, 30, 40, 40};
const double service_charges[] = {0, 0.3, 0.4, 0.3, 0.4, 0.3, 0.5, 0.5};

double get_day_charges(int day, int hours) {
    if (hours == 0) {
        return 0;
    }

    double result = min_charges[day];

    if (hours > 3) {
        result += hourly_charges[day] * (hours - 3);
    }

    if (result > max_charges[day]) {
        result = max_charges[day];
    }

    result += service_charges[day] * hours;

    return result;
}

double get_rental_charges(int start_day, int start_time, int end_day, int end_time) {
    if (end_day - start_day == 0) {
        int hours = end_time / 100 - start_time / 100;
        return get_day_charges(start_day, hours);
    }

    if (start_day > end_day) {
        end_day += 7;
    }

    double charges = 0.0;

    for (int current_day = start_day; current_day <= end_day; current_day++) {
        int hours = 0;

        if (current_day == start_day) {
            hours = 24 - (start_time / 100);
        } else if (current_day == end_day) {
            hours = end_time / 100;
        } else {
            hours = 24;
        }

        charges += get_day_charges(((current_day - 1) % 7) + 1, hours);
    }

    return charges;
}


int main(void) {
    int tc_num = 1;
    {
        printf("Test %d\n", tc_num++);
        printf("get_rental_charges(1, 200, 1, 900)\n");
        printf("Expected:$22.10\n");
        printf("Actual  :$%.2f\n",
               get_rental_charges(1, 200, 1, 900));
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        printf("get_rental_charges(4, 1500, 4, 1900)\n");
        printf("Expected:$19.10\n");
        printf("Actual  :$%.2f\n",
               get_rental_charges(4, 1500, 4, 1900));
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        printf("get_rental_charges(7, 1300, 7, 1800)\n");
        printf("Expected:$26.50\n");
        printf("Actual  :$%.2f\n",
               get_rental_charges(7, 1300, 7, 1800));
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        printf("get_rental_charges(1, 700, 2, 900)\n");
        printf("Expected:$68.70\n");
        printf("Actual  :$%.2f\n",
               get_rental_charges(1, 700, 2, 900));
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        printf("get_rental_charges(4, 1200, 6, 1200)\n");
        printf("Expected:$123.00\n");
        printf("Actual  :$%.2f\n",
               get_rental_charges(4, 1200, 6, 1200));
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        printf("get_rental_charges(7, 2200, 1, 300)\n");
        printf("Expected:$31.90\n");
        printf("Actual  :$%.2f\n",
               get_rental_charges(7, 2200, 1, 300));
        printf("\n");
    }
} 
