/*
    Name:
    Email:

*/
#include <stdio.h>

// write your answer below
void sum_of_neighbours(int arr[], int n) {
    if (n == 1) {
        return;
    }
    int result[n];

    for (int i = 1; i < n - 1; i++) {
        result[i] = arr[i - 1] + arr[i] + arr[i + 1];
    }

    // handle corner case
    result[0] = arr[0] + arr[1];
    result[n - 1] = arr[n - 1] + arr[n - 2];

    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
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