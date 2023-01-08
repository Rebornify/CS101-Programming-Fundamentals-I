#include <stdio.h>
#include <stdlib.h>

void union_of_2(int size1, int* arr1, int size2, int* arr2, int** result) {
    int* arr = malloc((size1 + size2) * sizeof(int));

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < size1 && j < size2) {
        arr[k++] = arr1[i] < arr2[j] ? arr1[i++] : arr2[j++];
    }

    while (i < size1) {
        arr[k++] = arr1[i++];
    }

    while (j < size2) {
        arr[k++] = arr2[j++];
    }
    
    *result = arr;
}

void print_array(int n, int arr[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int tc_num = 1;
    {
        int arr1[] = {1, 3, 5};
        int arr2[] = {2, 4, 6};
        int *result = NULL;
        int n1 = sizeof(arr1) / sizeof(int);
        int n2 = sizeof(arr2) / sizeof(int);
        union_of_2(n1, arr1, n2, arr2, &result);
        printf("Test %d\n", tc_num++);
        printf("Expected:1 2 3 4 5 6\n");
        printf("Actual  :");
        print_array(n1 + n2, result);
        printf("\n");
        free(result);
    }

    {
        int arr1[] = {1, 3, 5, 7};
        int arr2[] = {2, 4, 6};
        int *result = NULL;
        int n1 = sizeof(arr1) / sizeof(int);
        int n2 = sizeof(arr2) / sizeof(int);
        union_of_2(n1, arr1, n2, arr2, &result);
        printf("Test %d\n", tc_num++);
        printf("Expected:1 2 3 4 5 6 7\n");
        printf("Actual  :");
        print_array(n1 + n2, result);
        printf("\n");
        free(result);
    }

    {
        int arr1[] = {1, 3, 5};
        int arr2[] = {2, 4, 6, 8};
        int *result = NULL;
        int n1 = sizeof(arr1) / sizeof(int);
        int n2 = sizeof(arr2) / sizeof(int);
        union_of_2(n1, arr1, n2, arr2, &result);
        printf("Test %d\n", tc_num++);
        printf("Expected:1 2 3 4 5 6 8\n");
        printf("Actual  :");
        print_array(n1 + n2, result);
        printf("\n");
        free(result);
    }

    {
        int arr1[] = {1, 3, 5};
        int arr2[] = {7, 9};
        int *result = NULL;
        int n1 = sizeof(arr1) / sizeof(int);
        int n2 = sizeof(arr2) / sizeof(int);
        union_of_2(n1, arr1, n2, arr2, &result);
        printf("Test %d\n", tc_num++);
        printf("Expected:1 3 5 7 9\n");
        printf("Actual  :");
        print_array(n1 + n2, result);
        printf("\n");
        free(result);
    }

    {
        int arr1[] = {1, 3, 5, 8, 9};
        int arr2[] = {7, 9, 9};
        int *result = NULL;
        int n1 = sizeof(arr1) / sizeof(int);
        int n2 = sizeof(arr2) / sizeof(int);
        union_of_2(n1, arr1, n2, arr2, &result);
        printf("Test %d\n", tc_num++);
        printf("Expected:1 3 5 7 8 9 9 9\n");
        printf("Actual  :");
        print_array(n1 + n2, result);
        printf("\n");
        free(result);
    }
}