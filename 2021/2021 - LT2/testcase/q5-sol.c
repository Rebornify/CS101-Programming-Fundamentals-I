#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TC1 1
#define TC2 1
#define TC3 1
#define TC4 1
#define TC5 1

#if SINGLE_TC == 1
#define TC1 1
#define TC2 0
#define TC3 0
#define TC4 0
#define TC5 0
#endif

#if SINGLE_TC == 2
#define TC1 0
#define TC2 1
#define TC3 0
#define TC4 0
#define TC5 0
#endif

#if SINGLE_TC == 3
#define TC1 0
#define TC2 0
#define TC3 1
#define TC4 0
#define TC5 0
#endif

#if SINGLE_TC == 4
#define TC1 0
#define TC2 0
#define TC3 0
#define TC4 1
#define TC5 0
#endif

#if SINGLE_TC == 5
#define TC1 0
#define TC2 0
#define TC3 0
#define TC4 0
#define TC5 1
#endif

// typedef struct {
//     int hr;
//     int min;
//     bool is_am;
// } time;

// typedef struct {
//     int year;
//     int mth;
//     int day;
// } date;

// typedef struct {
//     date entry_date;
//     time start;
//     time end;
// } entry;

int to_24_hrs__(time *t) {
    int hr = t->hr;
    int min = t->min;

    if (!t->is_am && t->hr != 12) {
        hr += 12;
    } else if (t->is_am && hr == 12) {
        hr = 0;
    }

    return hr * 60 + min;
}

bool is_overlapping__(entry *e1, entry *e2) {
    if (e1->entry_date.day != e2->entry_date.day
            || e1->entry_date.mth != e2->entry_date.mth 
            || e1->entry_date.year != e2->entry_date.year) {
                // printf("123\n");
        return false;
    } 
    return to_24_hrs__(&(e1->start)) < to_24_hrs__(&(e2->end)) && to_24_hrs__(&(e2->start)) < to_24_hrs__(&(e1->end));
}

int expected_get_contact_time(entry *entries1, int n1, entry *entries2, int n2) {
    int count = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (is_overlapping__(&entries1[i], &entries2[j])) {
                int s1 = to_24_hrs__(&entries1[i].start);
                int s2 = to_24_hrs__(&entries2[j].start);

                int e1 = to_24_hrs__(&entries1[i].end);
                int e2 = to_24_hrs__(&entries2[j].end);

                int overlap_s = s1 > s2 ? s1 : s2;
                int overlap_e = e1 < e2 ? e1 : e2;

                // printf("%d %d %d\n", overlap_e, overlap_s, overlap_e - overlap_s);
                // printf("----\n");
                count += overlap_e - overlap_s;
            } else {
                // printf("XX\n");
            }
        }
    }
    return count;
}

int main(void) {
    int tc_num = 1;
    if (0) {
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

    if (0) {
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

    if (0) {
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


    /***   Secret test cases   ***/

    if (TC1) {
        tc_num = 1;
        double score = 1;

        entry entries1[] = {
            {{2021, 11, 11},{11, 22, true}, {11, 55, true}},
            {{2021, 11, 2},{11, 22, false}, {11, 55, false}},
            {{2021, 11, 22},{11, 22, false}, {11, 55, false}},
            };

        entry entries2[] = {
            {{2021, 11, 2},{9, 9, false}, {11, 33, false}},
            {{2021, 11, 11},{9, 9, true}, {11, 33, true}},
            {{2021, 11, 23},{11, 22, false}, {11, 55, false}},
            };


        int expected = expected_get_contact_time(entries1, sizeof(entries1)/sizeof(entry), entries2, sizeof(entries2)/sizeof(entry));
        int actual = get_contact_time(entries1, sizeof(entries1)/sizeof(entry), entries2, sizeof(entries2)/sizeof(entry));

        printf("Test %d\n", tc_num);
        printf("Expected : %d\n", expected);
        printf("Actual : %d\n", actual);
        printf("\n");
        
        if (expected != actual) {
            score = 0;
        }
        printf("%s,%d,%.2f\n\n", __FILE__, tc_num, score);
    }

    if (TC2) {
        tc_num = 2;
        double score = 1;

        // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
        //   -------------------     -----------             ----------
        //           --------------      ---      ------------------
        entry entries1[] = {
            {{2021, 11, 1},{1, 1, true}, {10, 10, true}},
            {{2021, 11, 1},{8, 8, false}, {11, 33, false}},
            {{2021, 11, 1},{12, 12, false}, {3, 15, false}},
            };
        entry entries2[] = {
            {{2021, 11, 1},{5, 5, true}, {11, 11, true}},
            {{2021, 11, 1},{4, 4, false}, {10, 10, false}},
            {{2021, 11, 1},{1, 13, false}, {2, 14, false}},
            };


        int expected = expected_get_contact_time(entries1, sizeof(entries1)/sizeof(entry), entries2, sizeof(entries2)/sizeof(entry));
        int actual = get_contact_time(entries1, sizeof(entries1)/sizeof(entry), entries2, sizeof(entries2)/sizeof(entry));

        printf("Test %d\n", tc_num);
        printf("Expected : %d\n", expected);
        printf("Actual : %d\n", actual);
        printf("\n");
        
        if (expected != actual) {
            score = 0;
        }
        printf("%s,%d,%.2f\n\n", __FILE__, tc_num, score);
    }

    if (TC3) {
        tc_num = 3;
        double score = 1;

        entry entries1[] = {
            {{2021, 11, 1},{11, 0, false}, {11, 59, false}},
            {{2021, 11, 2},{12, 0, true}, {1, 0, true}},
            };

        entry entries2[] = {
            {{2021, 11, 1},{10, 0, false}, {11, 30, false}},
            {{2021, 11, 2},{12, 30, true}, {1, 30, true}},
            };

        int expected = expected_get_contact_time(entries1, sizeof(entries1)/sizeof(entry), entries2, sizeof(entries2)/sizeof(entry));
        int actual = get_contact_time(entries1, sizeof(entries1)/sizeof(entry), entries2, sizeof(entries2)/sizeof(entry));

        printf("Test %d\n", tc_num);
        printf("Expected : %d\n", expected);
        printf("Actual : %d\n", actual);
        printf("\n");
        
        if (expected != actual) {
            score = 0;
        }
        printf("%s,%d,%.2f\n\n", __FILE__, tc_num, score);
    }            

    if (TC4) {
        tc_num = 4;
        double score = 1;

        entry entries1[] = {
            {{2021, 11, 1},{0, 0, true}, {11, 11, false}},
            {{2021, 11, 3},{1, 1, true}, {2, 2, true}},
            {{2021, 11, 3},{3, 3, true}, {4, 4, true}},
            {{2021, 11, 3},{1, 1, false}, {2, 2, false}},
            {{2021, 11, 3},{3, 3, false}, {4, 4, false}},
            {{2021, 11, 4},{10, 10, true}, {2, 2, false}},

            };

        entry entries2[] = {
            {{2021, 11, 1},{1, 1, true}, {2, 2, true}},
            {{2021, 11, 1},{3, 3, true}, {4, 4, true}},
            {{2021, 11, 1},{1, 1, false}, {2, 2, false}},
            {{2021, 11, 1},{3, 3, false}, {4, 4, false}},
            {{2021, 11, 3},{0, 0, true}, {11, 11, false}},
            {{2021, 11, 4},{9, 9, true}, {11, 11, true}},
            {{2021, 11, 4},{1, 1, false}, {3, 3, false}},
            };


        int expected = expected_get_contact_time(entries1, sizeof(entries1)/sizeof(entry), entries2, sizeof(entries2)/sizeof(entry));
        int actual = get_contact_time(entries1, sizeof(entries1)/sizeof(entry), entries2, sizeof(entries2)/sizeof(entry));

        printf("Test %d\n", tc_num);
        printf("Expected : %d\n", expected);
        printf("Actual : %d\n", actual);
        printf("\n");
        
        if (expected != actual) {
            score = 0;
        }
        printf("%s,%d,%.2f\n\n", __FILE__, tc_num, score);
    }            

}