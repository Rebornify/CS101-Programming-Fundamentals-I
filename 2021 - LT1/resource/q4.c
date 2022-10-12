#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int get_index(int arr_len, int final_index) {
    if (final_index < 0) {
        return arr_len + final_index;
    }
    return final_index % arr_len;
}

bool is_weak(int arr[], int arr_len, int n, int index) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += arr[get_index(arr_len, index + i)];
    }

    for (int i = 1; i <= n; i++) {
        sum += arr[get_index(arr_len, index - i)];
    }

    double mean = sum / (n * 2);

    if (arr[index] < mean) {
        return true;
    }
    return false;
}

void support(int arr[], int arr_len, int n) {
    for (int i = 0; i < arr_len; i++) {
        if (is_weak(arr, arr_len, n, i)) {
            arr[i] *= 1.5;
        }
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int tc_num = 1;
    {
        int arr[] = {2, 4, 3};
        printf("Test %d\n", tc_num++);
        printf("Expected:3 4 3\n");
        printf("Actual  :");
        support(arr, sizeof(arr)/sizeof(arr[0]), 1);
        print_array(arr, sizeof(arr)/sizeof(arr[0]));
        printf("\n");
    }
    
    {
        int arr[] = {5, 7, 11, 12, 1, 17, 23};
        printf("Test %d\n", tc_num++);
        printf("Expected:7 10 11 12 1 17 23\n");
        printf("Actual  :");
        support(arr, sizeof(arr)/sizeof(arr[0]), 1);
        print_array(arr, sizeof(arr)/sizeof(arr[0]));
        printf("\n");
    }

    {
        int arr[] = {9, 10, 4, 32, 16, 18, 10};
        printf("Test %d\n", tc_num++);
        printf("Expected:13 15 6 32 16 18 15\n");
        printf("Actual  :");
        support(arr, sizeof(arr)/sizeof(arr[0]), 2);
        print_array(arr, sizeof(arr)/sizeof(arr[0]));
        printf("\n");
    }

    {
        int arr[] = {9, 10, 4, 32, 16, 18};
        printf("Test %d\n", tc_num++);
        printf("Expected:13 15 6 32 16 18\n");
        printf("Actual  :");
        support(arr, sizeof(arr)/sizeof(arr[0]), 3);
        print_array(arr, sizeof(arr)/sizeof(arr[0]));
        printf("\n");
    }

}