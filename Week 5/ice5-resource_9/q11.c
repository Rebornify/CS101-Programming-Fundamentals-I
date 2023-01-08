#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_perfect_num(int num) {
    if (num < 0) {
        return false;
    }

    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    if (sum == num) {
        return true;
    }
    
    return false;
}

int main(void) {
    {
        printf("Test 1\n");
        int result = is_perfect_num(6);
        printf("Expected:Pass\n");
        printf("Actual  :%s\n\n", result ? "Pass" : "Fail");
    }

    {
        printf("Test 2\n");
        int result = is_perfect_num(28);
        printf("Expected:Pass\n");
        printf("Actual  :%s\n\n", result ? "Pass" : "Fail");
    }

    {
        printf("Test 3\n");
        int result = is_perfect_num(496);
        printf("Expected:Pass\n");
        printf("Actual  :%s\n\n", result ? "Pass" : "Fail");
    }

    {
        printf("Test 4\n");
        int result = is_perfect_num(8128);
        printf("Expected:Pass\n");
        printf("Actual  :%s\n\n", result ? "Pass" : "Fail");
    }

    {
        printf("Test 5\n");
        int result = is_perfect_num(123);
        printf("Expected:Fail\n");
        printf("Actual  :%s\n\n", result ? "Pass" : "Fail");
    }
 
    {
        printf("Test 6\n");
        int result = is_perfect_num(-8128);
        printf("Expected:Fail\n");
        printf("Actual  :%s\n\n", result ? "Pass" : "Fail");
    }

    {
        printf("Test 7\n");
        int result = is_perfect_num(1);
        printf("Expected:Fail\n");
        printf("Actual  :%s\n\n", result ? "Pass" : "Fail");
    }
}
