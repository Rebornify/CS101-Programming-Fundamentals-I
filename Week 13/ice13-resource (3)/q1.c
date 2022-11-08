#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_sum_sublist(int numbers[], int k, int index) {
    int sum = 0;
    
    for (int i = 0; i < k; i++) {
        sum += numbers[index + i];
    }

    return sum;
}

int* get_max_sum_sublist(int numbers[], int n, int k) {
    if (n < k) {
        return NULL;
    }

    int max = get_sum_sublist(numbers, k, 0);

    int index = 0;

    for (int i = 1; i < n - k + 1; i++) {
        int sum = get_sum_sublist(numbers, k, i);

        if (sum > max) {
            max = sum;
            index = i;
        }
    }
    
    return &numbers[index];
}

void print_array(int *arr, int n) {
    if (arr == NULL) {
        printf("NULL\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", *arr++);
    }
    printf("\n");
}

int main(void) {
    {
        int input[] = {11, 3, 9, 8, 13, 0, 12};
        int k = 4;
        int *result = get_max_sum_sublist(input, sizeof(input) / sizeof(int), k);
        printf("Expected:3 9 8 13\n");
        printf("Actual  :");
        print_array(result, k);
        printf("\n");
    }

    {
        int input[] = {11, 3, 9, 8, 7, 2};
        int k = 3;
        int *result = get_max_sum_sublist(input, sizeof(input) / sizeof(int), k);
        printf("Expected:9 8 7\n");
        printf("Actual  :");
        print_array(result, k);
        printf("\n");
    }
    {
        int input[] = {11, 3};
        int k = 3;
        int *result = get_max_sum_sublist(input, sizeof(input) / sizeof(int), k);
        printf("Expected:NULL\n");
        printf("Actual  :");
        print_array(result, k);
        printf("\n");
    }
}