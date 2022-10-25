#include <stdio.h>


typedef struct {
    int hr;
    int min;
    bool is_am;
} time;

typedef struct {
    int year;
    int mth;
    int day;
} date;

typedef struct {
    date entry_date;
    time start;
    time end;
} entry;



int main(void) {
    int tc_num = 1;
    {
        entry entries1[] = {
            {{2021, 11, 1}, {9, 30, true}, {10, 30, true}},
            {{2021, 11, 2}, {9, 0, true}, {11, 30, true}},
            {{2021, 11, 3}, {10, 30, true}, {11, 30, true}},
            {{2021, 11, 4}, {10, 30, true}, {10, 45, true}},
            {{2021, 11, 5}, {9, 30, true}, {11, 45, true}},
            {{2021, 11, 6}, {9, 0, true}, {10, 0, true}},
            {{2021, 11, 7}, {11, 0, true}, {11, 30, true}}
            };

        entry entries2[] = {
            {{2021, 11, 1}, {10, 0, true}, {11, 0, true}}, // 30 minutes 
            {{2021, 11, 2}, {10, 0, true}, {11, 0, true}}, // 60 minutes
            {{2021, 11, 3}, {10, 0, true}, {11, 0, true}}, // 30 minutes
            {{2021, 11, 4}, {10, 0, true}, {11, 0, true}}, // 15 minutes
            {{2021, 11, 5}, {10, 0, true}, {11, 0, true}}, // 60 minutes
            {{2021, 11, 6}, {10, 0, true}, {11, 0, true}}, // 0 minute
            {{2021, 11, 7}, {10, 0, true}, {11, 0, true}}  // 0 minute
            };
        printf("Test Case %d\n", tc_num++);
        printf("Expected:195\n");
        printf("Actual  :%d\n", get_contact_time(entries1, sizeof(entries1)/sizeof(entry), entries2, sizeof(entries2)/sizeof(entry)));
        printf("\n");
    }

        {
        entry entries1[] = {
            {{2021, 11, 3},{12, 0, true}, {2, 0, true}},
            {{2021, 11, 1},{12, 0, false}, {1, 0, false}}};

        entry entries2[] = {
            {{2021, 11, 1},{11, 0, true}, {2, 0, false}},   // 60
            {{2021, 11, 3},{12, 0, true}, {12, 5, true}}};  // 5 
        printf("Test Case %d\n", tc_num++);
        printf("Expected:65\n");
        printf("Actual  :%d\n", get_contact_time(entries1, sizeof(entries1)/sizeof(entry), entries2, sizeof(entries2)/sizeof(entry)));
        printf("\n");
    }

    {
        entry entries1[] = {
            {{2021, 11, 1},{9, 0, true}, {10, 0, true}},
            {{2021, 11, 2},{9, 0, true}, {10, 0, true}}};

        entry entries2[] = {
            {{2021, 11, 3},{1, 30, true}, {1, 0, true}},
            {{2021, 11, 5},{12, 30, true}, {12, 40, true}}};
        printf("Test Case %d\n", tc_num++);
        printf("Expected:0\n");
        printf("Actual  :%d\n", get_contact_time(entries1, sizeof(entries1)/sizeof(entry), entries2, sizeof(entries2)/sizeof(entry)));
        printf("\n");
    }
}