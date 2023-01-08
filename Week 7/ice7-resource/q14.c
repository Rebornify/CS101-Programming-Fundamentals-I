#include <stdio.h>
#include <string.h>

int range(int numbers[], int n) {
    if (n == 1) {
        return 1;
    }

    int largest = numbers[0];
    int smallest = numbers[0];

    for (int i = 1; i < n; i++) {
        if (numbers[i] > largest) {
            largest = numbers[i];
        } else if (numbers[i] < smallest) {
            smallest = numbers[i];
        }
    }

    if (largest == smallest) {
        return 1;
    }

    return largest - smallest;
}

int main(void) {
    {
        printf("Test 1\n");
        int numbers[] = {5, 7, 19, 2, 3, 5};
        int result = range(numbers, 6);
        printf("Expected:17\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 2\n");
        int numbers[] = {31};
        int result = range(numbers, 1);
        printf("Expected:1\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 3\n");
        int numbers[] = {31, 31};
        int result = range(numbers, 2);
        printf("Expected:1\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}