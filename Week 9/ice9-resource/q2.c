#include <stdio.h>

void print_largest_two(int arr[], int n) {
    if (n == 1) {
        printf("#1 = %d", arr[0]);
        return;
    }

    int num1 = arr[0] > arr[1] ? arr[0] : arr[1];
    int num2 = arr[0] < arr[1] ? arr[0] : arr[1];

    for (int i = 2; i < n; i++) {
        if (arr[i] > num1) {
            num2 = num1;
            num1 = arr[i];
        } else if (arr[i] > num2) {
            num2 = arr[i];
        }
    }
    
    printf("#1 = %d, #2 = %d", num1, num2);
}

int main(void) {
    {
        int numbers[] = {13, 5, 6, 11};
        printf("Test 1\n");
        printf("Expected:#1 = 13, #2 = 11\n");
        printf("Actual  :");
        print_largest_two(numbers, sizeof(numbers) / sizeof(int));
        printf("\n");
    }

    {
        int numbers[] = {13, 13, 6, 11};
        printf("Test 2\n");
        printf("Expected:#1 = 13, #2 = 13\n");
        printf("Actual  :");
        print_largest_two(numbers, sizeof(numbers) / sizeof(int));
        printf("\n");
    }

    {
        int numbers[] = {13, 11, 1, 8, 2, 3, 5, 6, 6, 13};
        printf("Test 3\n");
        printf("Expected:#1 = 13, #2 = 13\n");
        printf("Actual  :");
        print_largest_two(numbers, sizeof(numbers) / sizeof(int));
        printf("\n");
    }

    {
        int numbers[] = {13, 11, 1, 8, 2, 3, 5, 6, 6, 17};
        printf("Test 4\n");
        printf("Expected:#1 = 17, #2 = 13\n");
        printf("Actual  :");
        print_largest_two(numbers, sizeof(numbers) / sizeof(int));
        printf("\n");
    }

    {
        int numbers[] = {21, 11, 1, 8, 2, 3, 5, 6, 6, 17};
        printf("Test 1\n");
        printf("Expected:#1 = 21, #2 = 17\n");
        printf("Actual  :");
        print_largest_two(numbers, sizeof(numbers) / sizeof(int));
        printf("\n");
    }

    {
        int numbers[] = {1, 2};
        printf("Test 1\n");
        printf("Expected:#1 = 2, #2 = 1\n");
        printf("Actual  :");
        print_largest_two(numbers, sizeof(numbers) / sizeof(int));
        printf("\n");
    }

    {
        int numbers[] = {1};
        printf("Test 1\n");
        printf("Expected:#1 = 1\n");
        printf("Actual  :");
        print_largest_two(numbers, sizeof(numbers) / sizeof(int));
        printf("\n");
    }


}