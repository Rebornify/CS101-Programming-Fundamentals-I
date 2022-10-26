#include <stdio.h>

int partition(int arr[], int low, int high) {
    int i = low;
    for (int j = low; j <= high; j++) {
        if (arr[i] < arr[high]) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int partition_index = partition(arr, low, high);
        quicksort(arr, low, partition_index - 1);
        quicksort(arr, partition_index + 1, high);
    }
}

void print_array(int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    {
        int arr[] = {3, 7, 8, 5, 2, 1, 9, 5, 4};
        printf("Test 1\n");
        printf("Before:");
        print_array(sizeof(arr) / sizeof(int), arr);
        quicksort(arr, 0, sizeof(arr) / sizeof(int) - 1);
        printf("After :");
        print_array(sizeof(arr) / sizeof(int), arr);
        printf("\n");
    }

    {
        int arr[] = {1, 2, 4};
        printf("Test 1\n");
        printf("Before:");
        print_array(sizeof(arr) / sizeof(int), arr);
        quicksort(arr, 0, sizeof(arr) / sizeof(int) - 1);
        printf("After :");
        print_array(sizeof(arr) / sizeof(int), arr);
        printf("\n");
    }

    {
        int arr[] = {5, 3, 1};
        printf("Test 1\n");
        printf("Before:");
        print_array(sizeof(arr) / sizeof(int), arr);
        quicksort(arr, 0, sizeof(arr) / sizeof(int) - 1);
        printf("After :");
        print_array(sizeof(arr) / sizeof(int), arr);
        printf("\n");
    }

    {
        int arr[] = {5};
        printf("Test 1\n");
        printf("Before:");
        print_array(sizeof(arr) / sizeof(int), arr);
        quicksort(arr, 0, sizeof(arr) / sizeof(int) - 1);
        printf("After :");
        print_array(sizeof(arr) / sizeof(int), arr);
        printf("\n");
    }
}
