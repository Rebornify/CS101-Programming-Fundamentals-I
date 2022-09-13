#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int swap_digit_pairs(int n) {

}

int main(void) {
    {
        printf("Test 1\n");
        int result = swap_digit_pairs(1);
        printf("Expected:1\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 2\n");
        int result = swap_digit_pairs(32);
        printf("Expected:23\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 3\n");
        int result = swap_digit_pairs(90);
        printf("Expected:9\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 4\n");
        int result = swap_digit_pairs(971);
        printf("Expected:917\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 5\n");
        int result = swap_digit_pairs(382818);
        printf("Expected:838281\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 6\n");
        int result = swap_digit_pairs(-13);
        printf("Expected:-31\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 7\n");
        int result = swap_digit_pairs(-1347);
        printf("Expected:-3174\n");
        printf("Actual  :%d\n\n", result);
    }
}