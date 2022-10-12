#include <stdio.h>
#include <string.h>

int index_of(int numbers[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (numbers[i] == target) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    {
        printf("Test 1\n");
        int numbers[] = {5, 7, 9, 2, 3, 5};
        int result = index_of(numbers, 6, 5);
        printf("Expected:0\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}