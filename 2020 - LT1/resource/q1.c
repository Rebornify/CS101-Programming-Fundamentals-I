/*
    Name:
    Email:

*/
#include <stdio.h>

// write your answer below

void sum_of_neighbours(int numbers[], int length) {
    if (length == 1) {
        return;
    }
    
    int copy_numbers[length];
    for (int i = 0; i < length; i++) {
        copy_numbers[i] = numbers[i];
    }

    numbers[0] = copy_numbers[0] + copy_numbers[1];
    numbers[length - 1] = copy_numbers[length - 2] + copy_numbers[length - 1];
    for (int i = 1; i < length - 1; i++) {
        numbers[i] = copy_numbers[i] + copy_numbers[i - 1] + copy_numbers[i + 1];
    }
}

// do not edit the main method.

int main(void) {
    int test_num = 1;

    {
        int arr[] = {1};
        int n = sizeof(arr) / sizeof(int);
        sum_of_neighbours(arr, n);
        printf("Test %d\n", test_num++);
        printf("Expected:1\n");
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }

    {
        int arr[] = {1, 2};
        int n = sizeof(arr) / sizeof(int);
        sum_of_neighbours(arr, n);
        printf("Test %d\n", test_num++);
        printf("Expected:3 3\n");
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }

    {
        int arr[] = {1, 2, 3};
        int n = sizeof(arr) / sizeof(int);
        sum_of_neighbours(arr, n);
        printf("Test %d\n", test_num++);
        printf("Expected:3 6 5\n");
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }

    {
        int arr[] = {10, 20, 30, 40, 50};
        int n = sizeof(arr) / sizeof(int);
        sum_of_neighbours(arr, n);
        printf("Test %d\n", test_num++);
        printf("Expected:30 60 90 120 90\n");
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }
}