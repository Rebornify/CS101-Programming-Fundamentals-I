#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int swap_digit_pairs(int n) {
    bool is_positive = true;
    if (n < 0) {
        n *= -1;
        is_positive = false;
    }

    int result = 0;
    int place = 1;

    while (n > 10) {
        int pair = n % 100;
        int digit_1 = pair % 10;
        int digit_2 = pair / 10;
        
        pair = digit_1 * 10 + digit_2;
        result += pair * place;
        
        place *= 100;
        n /= 100;
    }

    if (n > 0) {
        result += n * place;
    }

    if (!is_positive) {
        result *= -1;
    }
    
    return result;
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