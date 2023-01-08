#include <stdio.h>

int range(int arr[], int n) {
    int lowest = arr[0] < arr[1] ? arr[0] : arr[1];
    int highest = arr[0] > arr[1] ? arr[0] : arr[1];

    for (int i = 2; i < n; i++) {
        if (arr[i] < lowest) {
            lowest = arr[i];
        } else if (arr[i] > highest) {
            highest = arr[i];
        }
    }

    return highest - lowest;
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
}