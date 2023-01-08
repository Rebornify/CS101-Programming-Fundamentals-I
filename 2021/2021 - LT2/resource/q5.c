#include <stdio.h>
#include <stdbool.h>


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

int get_num_mins_since_midnight(time *t) {
    int hr = t->hr;
    int min = t->min;

    if (!t->is_am && t->hr != 12) {
        hr += 12;
    } else if (t->is_am && hr == 12) {
        hr = 0;
    }

    return hr * 60 + min;
}

bool is_overlapping(entry *e1, entry *e2) {
    if (e1->entry_date.day != e2->entry_date.day || e1->entry_date.mth != e2->entry_date.mth 
            || e1->entry_date.year != e2->entry_date.year) {
        return false;
    }

    return get_num_mins_since_midnight(&(e1->start)) < get_num_mins_since_midnight(&(e2->end))
            && get_num_mins_since_midnight(&(e2->start)) < get_num_mins_since_midnight(&(e1->end));
}

int get_contact_time(entry *entries1, int n1, entry *entries2, int n2) {
    int count = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (is_overlapping(&entries1[i], &entries2[j])) {
                int s1 = get_num_mins_since_midnight(&entries1[i].start);
                int s2 = get_num_mins_since_midnight(&entries2[j].start);

                int e1 = get_num_mins_since_midnight(&entries1[i].end);
                int e2 = get_num_mins_since_midnight(&entries2[j].end);

                int overlap_s = s1 > s2 ? s1 : s2;
                int overlap_e = e1 < e2 ? e1 : e2;
                count += overlap_e - overlap_s;
            } 
        }
    }
    return count;
}

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