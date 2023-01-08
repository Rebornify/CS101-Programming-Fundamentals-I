#include <stdio.h>

int get_smallest_pair(int num) {
    if (num < 10) {
        return -1;
    }

    int smallest = num % 100;
    num /= 10;

    while (num > 10) {
        int current = num % 100;
        if (current < smallest) {
            smallest = current;
        }
        num /= 10;
    }

    return smallest;
}

int main(void) {
    {
        printf("Test 1\n");
        printf("Expected:23\n");
        int result = get_smallest_pair(2345);
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 2\n");
        printf("Expected:2\n");
        int result = get_smallest_pair(10245);
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 3\n");
        printf("Expected:-1\n");
        int result = get_smallest_pair(1);
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 4\n");
        printf("Expected:10\n");
        int result = get_smallest_pair(10);
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}
