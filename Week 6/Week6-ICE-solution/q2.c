#include <stdio.h>
#include <stdlib.h>

int gcd(int num1, int num2) {
    if (num1 == 0) {
        return num2;
    }
    
    if (num2 == 0) {
        return num1;
    }

    num1 = abs(num1);
    num2 = abs(num2);

    int start = num1;
    if (abs(num2) < start) {
        start = abs(num2);
    }

    for (int i = start; i > 0; i--) {
        if (num1 % i == 0 && num2 % i == 0) {
            return i;
        }
    }
    return 1;
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
