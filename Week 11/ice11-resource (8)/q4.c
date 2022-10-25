#include <stdio.h>
#include <stdlib.h>

int intersection_of_2(int size1, int* arr1, int size2, int* arr2, int** result) {
    int size = size1 > size2 ? size1 : size2;
    int* arr = malloc(sizeof(int) * size);

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else {
            arr[k++] = arr1[i++];
            j++;
        }
    }
    
    if (k > 0) {
        arr = realloc(arr, sizeof(int) * k);
        *result = arr;
    } else {
        free(arr);
    }
    return k;
}

void print_array(int n, int arr[n]) {
    if (n == 0) {
        printf("><\n");
        return;
    }
    printf(">");
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d<\n", arr[n - 1]);
}

int main(void) {
    {
        int arr1[] = {1, 3, 5};
        int arr2[] = {3, 4, 5, 6};
        int *result;
        int n = intersection_of_2(sizeof(arr1) / sizeof(int), arr1, sizeof(arr2) / sizeof(int), arr2, &result);
        printf("Test 1\n");
        printf("Expected:>3 5<\n");
        printf("Actual  :");
        print_array(n, result);
        printf("\n");
        free(result);
    }

    {
        int arr1[] = {1, 3, 5};
        int arr2[] = {4, 6, 9, 10};
        int *result;
        int n = intersection_of_2(sizeof(arr1) / sizeof(int), arr1, sizeof(arr2) / sizeof(int), arr2, &result);
        printf("Test 2\n");
        printf("Expected:><\n");
        printf("Actual  :");
        print_array(n, result);
        printf("\n");
        free(result);
    }

    {
        int arr1[] = {1, 3, 5, 9, 11};
        int arr2[] = {4, 6, 9, 10};
        int *result;
        int n = intersection_of_2(sizeof(arr1) / sizeof(int), arr1, sizeof(arr2) / sizeof(int), arr2, &result);
        printf("Test 3\n");
        printf("Expected:>9<\n");
        printf("Actual  :");
        print_array(n, result);
        printf("\n");
        free(result);
    }

    {
        //
        int arr1[] = {1, 3, 5, 5};
        int arr2[] = {3, 5, 5, 9};
        int *result;
        int n = intersection_of_2(sizeof(arr1) / sizeof(int), arr1, sizeof(arr2) / sizeof(int), arr2, &result);
        printf("Test 4\n");
        printf("Expected:>3 5 5<\n");
        printf("Actual  :");
        print_array(n, result);
        printf("\n");
        free(result);
    }
}