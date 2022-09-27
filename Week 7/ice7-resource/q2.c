#include <stdio.h>

int count_odd_numbers(int numbers[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (numbers[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

int main(void) {
    {
        printf("Test 1\n");
        int values[] = {1, 3, 5};
        int result = count_odd_numbers(values, sizeof(values)/sizeof(int));
        printf("Expected:3\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 2\n");
        int values[] = {20, 3, 5, 2, 10, 2, 4, 6, 8, 10};
        int result = count_odd_numbers(values, sizeof(values)/sizeof(int));
        printf("Expected:2\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 3\n");
        int values[] = {20, 4, 2, 10, 2, 4};
        int result = count_odd_numbers(values, sizeof(values)/sizeof(int));
        printf("Expected:0\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

}
