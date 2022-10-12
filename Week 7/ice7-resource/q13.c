#include <stdio.h>
#include <string.h>

int last_index_of(int numbers[], int n, int target) {
    for (int i = n - 1; i >= 0; i--) {
        if (numbers[i] == target) {
            return i;
        }
    }
    return -1;
}

int main(void) {
    {
        printf("Test 1\n");
        int numbers[] = {6, 7, 9, 2, 3, 6};
        int result = last_index_of(numbers, 6, 6);
        printf("Expected:5\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}