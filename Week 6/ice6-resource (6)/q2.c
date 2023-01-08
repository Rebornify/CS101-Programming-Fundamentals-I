#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int num1, int num2) {
    num1 = abs(num1);
    num2 = abs(num2);

    if (num1 < num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    while (num2 != 0) {
        int r = num1 % num2;
        num1 = num2;
        num2 = r;
    }
    
    return num1;
}

int main(void) {
    {
        printf("Test 1\n");
        printf("Expected:3\n");
        int result = gcd(9, 12);
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 2\n");
        printf("Expected:1\n");
        int result = gcd(1, 0);
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 3\n");
        printf("Expected:1\n");
        int result = gcd(3, 5);
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 4\n");
        printf("Expected:3\n");
        int result = gcd(-3, -6);
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 5\n");
        printf("Expected:3\n");
        int result = gcd(-3, -6);
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 5\n");
        printf("Expected:0\n");
        int result = gcd(0, 0);
        printf("Actual  :%d\n", result);
        printf("\n");
    }

}
