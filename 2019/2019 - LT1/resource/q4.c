/*
   Name :
   Email:
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int rearrange_digits(int num, int pivot) {
    bool is_negative = false;

    if (num < 0) {
        is_negative = true;
        num = -num;
    }

    int smaller = 0;
    int num_smaller = 0;
    int larger = 0;
    int num_larger = 0;
    int equal = 0;
    int num_equal = 0;

    while (num > 0) {
        int digit = num % 10;

        if (digit > pivot) {
            larger = digit * (int)pow(10, num_larger) + larger;
            num_larger++;
        } else if (digit < pivot) {
            smaller = digit * (int)pow(10, num_smaller) + smaller;
            num_smaller++;
        } else {
            equal = digit * (int)pow(10, num_equal) + equal;
            num_equal++; 
        }

        num /= 10;
    }

    int result = (int)pow(10, num_smaller) * equal 
            + smaller
            + (int)pow(10, num_smaller + num_equal) * larger;


    if (is_negative) {
        return -result;
    }
    return result;
}

int main(void) {
    {
        printf("Test 1\n");
        int result = rearrange_digits(415, 3);
        printf("Expected:451\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 2\n");
        int result = rearrange_digits(123454321, 3);
        printf("Expected:454331221\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 3\n");
        int result = rearrange_digits(61728394, 5);
        printf("Expected:67891234\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 4\n");
        int result = rearrange_digits(61728394, 0);
        printf("Expected:61728394\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 5\n");
        int result = rearrange_digits(6900, 9);
        printf("Expected:9600\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 6\n");
        int result = rearrange_digits(-1245, 3);
        printf("Expected:-4512\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}

