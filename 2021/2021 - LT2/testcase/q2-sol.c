#include <stdio.h>
#include <limits.h>

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

int expected_range(int arr[], int n) {
    int highest = arr[0];
    int lowest = arr[0];

    for (int i = 0; i < n; i++) {
        if (arr[i] > highest) {
            highest = arr[i];
        }
        if (arr[i] < lowest) {
            lowest = arr[i];
        }
    }

    return highest - lowest;
}

int main(void) {
    int tc_num = 1;
    if (0) {
        int input[] = {1,2,3,4};
        printf("Test %d  :range((int[]){1,2,3,4}, 4)\n", tc_num++);
        printf("Expected:3\n");
        printf("Actual  :%d\n", range(input, sizeof(input)/sizeof(input[0])));
        printf("\n");
    }


    if (0) {
        int input[] = {3, 1, 6};
        printf("Test %d  :range((int[]){3, 1, 6}, 3)\n", tc_num++);
        printf("Expected:5\n");
        printf("Actual  :%d\n", range(input, sizeof(input)/sizeof(input[0])));
        printf("\n");
    }

    if (0) {
        int input[] = {1, 1, 1, 1, 1};
        printf("Test %d  :range((int[]){1, 1, 1, 1, 1}, 5)\n", tc_num++);
        printf("Expected:0\n");
        printf("Actual  :%d\n", range(input, sizeof(input)/sizeof(input[0])));
        printf("\n");
    }


    /***   Secret test cases   ***/

    if (TC1) {
        tc_num = 1;
        double score = 3;

        int input[] = {100, 10, 30, 200, 50, 400, 7, 8, 9};
        int len = sizeof(input) / sizeof(input[0]);
        printf("Test %d  :range((int[]){100, 10, 30, 200, 50, 400, 7, 8, 9}, %d)\n", tc_num, len);
        printf("Expected:%d\n", expected_range(input, len));
        printf("Actual  :%d\n", range(input, len));
        printf("\n");
        
        if (expected_range(input, len) != range(input, len)) {
            score = 0;
        }
        printf("%s,%d,%.2f\n\n", __FILE__, tc_num, score);
    }

    if (TC2) {
        tc_num = 2;
        double score = 1;

        int input[] = {-1000, 2, 0, -499, 499};
        int len = sizeof(input) / sizeof(input[0]);
        printf("Test %d  :range((int[]){-1000, 2, 0, -499, 499}, %d)\n", tc_num, len);
        printf("Expected:%d\n", expected_range(input, len));
        printf("Actual  :%d\n", range(input, len));
        printf("\n");
        
        if (expected_range(input, len) != range(input, len)) {
            score = 0;
        }
        printf("%s,%d,%.2f\n\n", __FILE__, tc_num, score);
    }

    if (TC3) {
        tc_num = 3;
        double score = 1;

        int input[] = {1000, -1000, INT_MIN / 2, 0, 0, 0, INT_MAX / 2, 0, 0, 0};
        int len = sizeof(input) / sizeof(input[0]);
        printf("Test %d  :range((int[]){1000, -1000, INT_MIN / 2, 0, 0, 0, INT_MAX / 2, 0, 0, 0}, %d)\n", tc_num, len);
        printf("Expected:%d\n", expected_range(input, len));
        printf("Actual  :%d\n", range(input, len));
        printf("\n");
        
        if (expected_range(input, len) != range(input, len)) {
            score = 0;
        }
        printf("%s,%d,%.2f\n\n", __FILE__, tc_num, score);
    }

    if (TC4) {
        tc_num = 4;
        double score = 1;

        int input[] = {-100, -200, -300};
        int len = sizeof(input) / sizeof(input[0]);
        printf("Test %d  :range((int[]){-100, -200, -300}, %d)\n", tc_num, len);
        printf("Expected:%d\n", expected_range(input, len));
        printf("Actual  :%d\n", range(input, len));
        printf("\n");
        
        if (expected_range(input, len) != range(input, len)) {
            score = 0;
        }
        printf("%s,%d,%.2f\n\n", __FILE__, tc_num, score);
    }

    // printf("%s,%.2f\n\n", __FILE__, total_score);
}