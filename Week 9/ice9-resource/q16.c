#include <stdio.h>

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min_i = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_i]) {
                min_i = j;
            }

            if (min_i != i) {
                swap(&arr[min_i], &arr[i]);
            }
        }
    }
}

int main(void) {
    int tc_num = 0;
    {
        int arr[] = {6, 1, 5, 3, 7, 9};
        int n = sizeof(arr)/sizeof(int);
        printf("Test %d\n", ++tc_num);
        printf("Expected:1 3 5 6 7 9\n");
        selection_sort(arr, n);
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }

    {
        int arr[] = {7, 7, 6, 1, 5, 3, 31, 7, 9, 11};
        int n = sizeof(arr)/sizeof(int);
        printf("Test %d\n", ++tc_num);
        printf("Expected:1 3 5 6 7 7 7 9 11 31\n");
        selection_sort(arr, n);
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }

    {
        int arr[] = {7};
        int n = sizeof(arr)/sizeof(int);
        printf("Test %d\n", ++tc_num);
        printf("Expected:7\n");
        selection_sort(arr, n);
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }

    {
        int arr[] = {7, 2};
        int n = sizeof(arr)/sizeof(int);
        printf("Test %d\n", ++tc_num);
        printf("Expected:2 7\n");
        selection_sort(arr, n);
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }
}