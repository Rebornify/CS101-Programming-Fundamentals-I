#include <stdio.h>
#include <stdlib.h>

int symmetric_difference(int sorted1[], int n1, int sorted2[], int n2, int **result) {
    int *ans = calloc(n1 + n2, sizeof(int));

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 && j < n2) {
        if (sorted1[i] < sorted2[j]) {
            ans[k++] = sorted1[i++];
        } else if (sorted1[i] > sorted2[j]) {
            ans[k++] = sorted2[j++];
        } else {
            i++;
            j++;
        }
    }

    while (i < n1) {
        ans[k++] = sorted1[i++];
    }

    while (j < n2) {
        ans[k++] = sorted2[j++];
    }

    *result = realloc(ans, k * sizeof(int));
    return k;
}

void print_array(int *arr, int n) {
    if (arr == NULL) {
        printf("** EMPTY **\n");
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[n - 1]);
}

int main(void) {
    int num = 1;
    {
        int arr1[] = {1, 3, 4};
        int arr2[] = {2, 3, 5};
        int *result;
        int size = symmetric_difference(arr1, sizeof(arr1)/sizeof(int), arr2, sizeof(arr2)/sizeof(int), &result);
        printf("Test %d\n", num++);
        printf("Expected:1 2 4 5\n");
        printf("Actual  :");
        print_array(result, size);
        free(result);
        printf("\n");
    }
    {
        int arr1[] = {3, 5};
        int arr2[] = {2, 3, 5};
        int *result;
        int size = symmetric_difference(arr1, sizeof(arr1)/sizeof(int), arr2, sizeof(arr2)/sizeof(int), &result);
        printf("Test %d\n", num++);
        printf("Expected:2\n");
        printf("Actual  :");
        print_array(result, size);
        free(result);
        printf("\n");
    }
        {
        int arr1[] = {2, 3, 5};
        int arr2[] = {2, 3};
        int *result;
        int size = symmetric_difference(arr1, sizeof(arr1)/sizeof(int), arr2, sizeof(arr2)/sizeof(int), &result);
        printf("Test %d\n", num++);
        printf("Expected:5\n");
        printf("Actual  :");
        print_array(result, size);
        free(result);
        printf("\n");
    }
        {
        int arr1[] = {2, 3};
        int arr2[] = {2, 3};
        int *result;
        int size = symmetric_difference(arr1, sizeof(arr1)/sizeof(int), arr2, sizeof(arr2)/sizeof(int), &result);
        printf("Test %d\n", num++);
        printf("Expected:5\n");
        printf("Actual  :");
        print_array(result, size);
        free(result);
        printf("\n");
    }
}