#include <stdio.h>
#include <string.h>
#include <ctype.h>

int mode(int numbers[], int n) {
    int mode = 0;
    int max_count = -1;

    int count;
    for (int i = 0; i < n; i += count) {
        count = 1;
        for (int j = i + 1; j < n; j++) {
            if (numbers[i] != numbers[j]) {
                break;
            } else {
                count++;
            }
        }

        if (count > max_count) {
            mode = numbers[i];
            max_count = count;
        }
    }

    return mode;
}

int main(void) {
    {
        printf("Test 1\n");
        int numbers[] = {3, 5, 5, 7, 7};
        int result = mode(numbers, 5);
        printf("Expected:5\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}