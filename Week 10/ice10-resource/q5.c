#include <stdio.h>
#include <time.h>

typedef struct {
    int day;
    int month;
    int year;
} date;

typedef struct {
    char name[100];
    date *birthday;
} student;

date get_current_year() {
    // there is no need to understand the code in this method
    time_t rawtime;
    time(&rawtime);
    struct tm *timeinfo = localtime(&rawtime);

    date current = {timeinfo->tm_mday, timeinfo->tm_mon + 1, 1900 + timeinfo->tm_year};
    return current;
}

int get_age(student *s) {
    return get_current_year().year - s->birthday->year;
}

int main(void) {
    {
        date birthday = {21, 12, 2017};
        student s = {"amy", &birthday};
        printf("Test 1\n");
        printf("Expected:%d\n", get_current_year().year - birthday.year);
        printf("Actual  :%d\n", get_age(&s));
        printf("\n");
    }

    {
        date birthday = {21, 10, 1972};
        student s = {"Tim", &birthday};
        printf("Test 2\n");
        printf("Expected:%d\n", get_current_year().year - birthday.year);
        printf("Actual  :%d\n", get_age(&s));
        printf("\n");
    }
    {
        date birthday = {21, 1, 2019};
        student s = {"Mary", &birthday};
        printf("Test 3\n");
        printf("Expected:%d\n", get_current_year().year - birthday.year);
        printf("Actual  :%d\n", get_age(&s));
        printf("\n");
    }
}