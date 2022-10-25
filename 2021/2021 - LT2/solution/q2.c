#include <stdio.h>

int range(int arr[], int n) {
    int largest = arr[0];
    int smallest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        } else if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    return largest - smallest;
}

int main(void) {
    int tc_num = 1;
    {
        int input[] = {1,2,3,4};
        printf("Test %d  :range((int[]){1,2,3,4}, 4)\n", tc_num++);
        printf("Expected:3\n");
        printf("Actual  :%d\n", range(input, sizeof(input)/sizeof(input[0])));
        printf("\n");
    }

    {
        int input[] = {3, 1, 6};
        printf("Test %d  :range((int[]){3, 1, 6}, 3)\n", tc_num++);
        printf("Expected:5\n");
        printf("Actual  :%d\n", range(input, sizeof(input)/sizeof(input[0])));
        printf("\n");
    }

    {
        int input[] = {1, 1, 1, 1, 1};
        printf("Test %d  :range((int[]){1, 1, 1, 1, 1}, 5)\n", tc_num++);
        printf("Expected:0\n");
        printf("Actual  :%d\n", range(input, sizeof(input)/sizeof(input[0])));
        printf("\n");
    }

    {
        int input[] = {-11, -7, -5, -4};
        printf("Test %d  :range((int[]){-11, -7, -5, -4}, 5)\n", tc_num++);
        printf("Expected:7\n");
        printf("Actual  :%d\n", range(input, sizeof(input)/sizeof(input[0])));
        printf("\n");
    }
}