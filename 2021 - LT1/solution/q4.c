#include <stdio.h>
#include <math.h>

int get_index(int idx, int arr_len) {
    if (idx < 0) {
        return idx + arr_len;
    }
    return idx % arr_len;
}

void support(int arr[], int arr_len, int n) {
    int result[arr_len];
    for (int i = 0; i < arr_len; i++) {
        int total = 0;

        for (int j = -n; j < 0; j++) {
            total += arr[get_index(i + j, arr_len)];
        }

        for (int j = 1; j <= n; j++) {
            total += arr[get_index(i + j, arr_len)];
        }

        double mean = total / (n * 2);
        if (arr[i] < mean) {
            result[i] = arr[i] * 1.5;
            // printf("[%.1lf]", result[i]);
        } else {
            result[i] = arr[i];
        }
    }
    for (int i = 0; i < arr_len; i++) {
        arr[i] = (int)result[i];
        // printf("%.1lf ", result[i]);
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
        // test 1
        int arr[] = {2, 4, 3};
        printf("Test %d\n", tc_num++);
        printf("Expected:3 4 3\n");
        printf("Actual  :");
        support(arr, sizeof(arr)/sizeof(arr[0]), 1);
        print_array(arr, sizeof(arr)/sizeof(arr[0]));
        printf("\n");
    }
    
    {
        // test 1
        int arr[] = {5, 7, 11, 12, 1, 17, 23};
        printf("Test %d\n", tc_num++);
        printf("Expected:7 10 11 12 1 17 23\n");
        printf("Actual  :");
        support(arr, sizeof(arr)/sizeof(arr[0]), 1);
        print_array(arr, sizeof(arr)/sizeof(arr[0]));
        printf("\n");
    }

    {
        
        // test 2
        int arr[] = {9, 10, 4, 32, 16, 18, 10};
        printf("Test %d\n", tc_num++);
        printf("Expected:13 15 6 32 16 18 15\n");
        printf("Actual  :");
        support(arr, sizeof(arr)/sizeof(arr[0]), 2);
        print_array(arr, sizeof(arr)/sizeof(arr[0]));
        printf("\n");
    }

    {
        int arr[] = {9, 10, 4, 32, 16, 18, 10};
        printf("Test %d\n", tc_num++);
        printf("Expected:13 15 6 32 16 18 15\n");
        printf("Actual  :");
        support(arr, sizeof(arr)/sizeof(arr[0]), 3);
        print_array(arr, sizeof(arr)/sizeof(arr[0]));
        printf("\n");
    }

}