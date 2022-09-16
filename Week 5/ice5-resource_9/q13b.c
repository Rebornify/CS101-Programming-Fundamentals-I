#include <stdio.h>
#include <stdbool.h>

int day_of_week(int day, int month, int year) {
    int yy = year % 100; 
    int year_code = (yy + (yy / 4)) % 7;

    int month_code;
    switch (month) {
        case 2:
        case 3:
        case 11:
            month_code = 3;
            break;

        case 1:
        case 10:
            month_code = 0;
            break;

        case 4:
        case 7:
            month_code = 6;
            break;

        case 9:
        case 12:
            month_code = 5;
            break;

        case 5:
            month_code = 1;
            break;

        case 6:
            month_code = 4;
            break;

        case 8:
            month_code = 2;
            break;
    }

    int century_code;
    switch (year / 100) {
        case 17:
        case 21:
            century_code = 4;
            break;

        case 18:
        case 22:
            century_code = 2;
            break;

        case 19:
        case 23:
            century_code = 0;
            break;

        case 20:
            century_code = 6;
            break;
    }

    int leap_year_code;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        leap_year_code = 1;
    } else {
        leap_year_code = 0;
    }

    int required_day = (year_code + month_code + century_code + day - leap_year_code) % 7;

    return required_day;
}

void print_calendar(month, year) {
    printf("Su Mo Tu We Th Fr Sa\n");
    int first_day = day_of_week(1, month, year);

    for (int i = first_day; i > 0; i--) {
        if (i == 7) {
            break;
        }
        printf("   ");
    }

    for int i = 1; i <= 7 - first_day; i++) {
        printf(" %d ", i);
    }

    printf("\n");

    int num_of_days;
    switch (month) {
        case 4:
        case 6:
        case 9:
        case 11:
            num_of_days = 30;
            break;
        
        case 2:
            num_of_days = 28;
            break;

        default:
            num_of_days = 31;
            break;
    }

    if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && (month == 2)) {
        num_of_days = 29;
    }

    for (int i = 8 - first_day; i < num_of_days; i += 7) {
        for (int j = i; j < i + 7; j++) {
            if (j < 10) {
                printf(" %d ", j);
            } else if (j <= num_of_days) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main(void) {
    print_calendar(5, 2028);
}