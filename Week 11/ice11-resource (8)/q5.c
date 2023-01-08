#include <stdio.h>

int binary_search(int n, int arr[], int x) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + ((high - low) / 2);
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

int main(void) {
    int tc_num = 1;
    {
        int arr[] = {2, 3, 7, 11, 15, 33, 35, 67, 78, 99};
        printf("Test Case %d\n", tc_num++);
        printf("Expected:7\n");
        int result = binary_search(sizeof(arr) / sizeof(int), arr, 67);
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        int arr[] = {2, 3, 7, 11, 15, 33, 35, 67, 78, 99};
        printf("Test Case %d\n", tc_num++);
        printf("Expected:9\n");
        int result = binary_search(sizeof(arr) / sizeof(int), arr, 99);
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        int arr[] = {2, 3, 7, 11, 15, 33, 35, 67, 78, 99};
        printf("Test Case %d\n", tc_num++);
        printf("Expected:0\n");
        int result = binary_search(sizeof(arr) / sizeof(int), arr, 2);
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        int arr[] = {2, 3, 7, 11, 15, 33, 35, 67, 78, 99};
        printf("Test Case %d\n", tc_num++);
        printf("Expected:-1\n");
        int result = binary_search(sizeof(arr) / sizeof(int), arr, 5);
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}