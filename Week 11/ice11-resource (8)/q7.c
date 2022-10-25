#include <stdio.h>



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
