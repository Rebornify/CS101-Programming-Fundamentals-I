#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int reverse(int num) {
    int result = 0;
    while (num != 0) {
        int digit = num % 10;
        result = result * 10 + digit;
        num /= 10;
    }
    return result;
}

int count_digits(int num) {
    int len = 0;
    while (num != 0) {
        num /= 10;
        ++len;
    }
    return len;
}
long flip_number(int num) {
    int len = count_digits(num);
    
    int half_len = len / 2;
    int left = num % (int)pow(10, half_len);

    int middle = 0;
    int right = right = num / (int)pow(10, half_len);

    if (len % 2 != 0) {
        middle = num / (int)pow(10, half_len) % 10;
        right = num / (int)pow(10, half_len + 1);
    }

    long result = 0;

    if (len % 2 != 0) {
        result = (long)reverse(right) * (int)pow(10, half_len + 1) 
                + middle * (long)pow(10, half_len) 
                + reverse(left);
    } else {
        result = (long)reverse(right) * (int)pow(10, half_len) 
                + reverse(left);
    }

    return result;
}

int main(void) {
    int tc_num = 1;
    {
        printf("Test %d\n", tc_num++);
        printf("Expected:7\n");
        printf("Actual  :%ld\n", flip_number(7));
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        printf("Expected:68\n");
        printf("Actual  :%ld\n", flip_number(68));
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        printf("Expected:87245\n");
        printf("Actual  :%ld\n", flip_number(78254));
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        printf("Expected:2758543\n");
        printf("Actual  :%ld\n", flip_number(5728345));
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        printf("Expected:-2\n");
        printf("Actual  :%ld\n", flip_number(-2));
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        printf("Expected:-23\n");
        printf("Actual  :%ld\n", flip_number(-23));
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        printf("Expected:-213\n");
        printf("Actual  :%ld\n", flip_number(-213));
        printf("\n");
    }

        {
        printf("Test %d\n", tc_num++);
        printf("Expected:-3254\n");
        printf("Actual  :%ld\n", flip_number(-2345));
        printf("\n");
    }
    
        {
        printf("Test %d\n", tc_num++);
        printf("Expected:-254\n");
        printf("Actual  :%ld\n", flip_number(-2045));
        printf("\n");
    }
    
    {
        // hard test case
        printf("Test %d\n", tc_num++);
        printf("Expected:4741274638\n");
        printf("Actual  :%ld\n", flip_number(2147483647));
        printf("\n");
    }

    {
        // hard test case
        printf("Test %d\n", tc_num++);
        printf("Expected:-4741284638\n");
        printf("Actual  :%ld\n", flip_number(-2147483648));
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        printf("Expected:1054\n");
        printf("Actual  :%ld\n", flip_number(100450));
        printf("\n");
    }
}
