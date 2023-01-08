/*
   Name :
   Email:
 */

#include <stdbool.h>
#include <stdio.h>

int num_half_it(int n1, int n2) {
    if (n1 <= 0 || n2 <= 0) {
        return -1;
    }

    int larger = n1 > n2 ? n1 : n2;
    int smaller = n1 < n2 ? n1 : n2;

    int count = 0;

    while (larger / 2 > smaller) {
        count++;
        larger /= 2;
    }

    return count;
}

int main(void) {

    {
        printf("Test 1\n");
        int result = num_half_it(100, 4);
        printf("Expected:4\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 2\n");
        int result = num_half_it(24, 7);
        printf("Expected:1\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 3\n");
        int result = num_half_it(135, 5);
        printf("Expected:4\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 4\n");
        int result = num_half_it(5, 135);
        printf("Expected:4\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 5\n");
        int result = num_half_it(132, 1);
        printf("Expected:7\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 6\n");
        int result = num_half_it(-1, 1);
        printf("Expected:-1\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 7\n");
        int result = num_half_it(1, 1);
        printf("Expected:0\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

}