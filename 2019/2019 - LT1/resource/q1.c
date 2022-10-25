/*
   Name :
   Email:
 */

#include <stdio.h>

int get_quadrant(int x, int y) {
    if (x == 0 || y == 0) {
        return 0;
    } else if (x > 0) {
        return y > 0 ? 1 : 4;
    } else {
        return y > 2 ? 1 : 3;
    }
}


int main(void) {
    {
        printf("Test 1\n");
        int result1 = get_quadrant(3, 5);
        printf("Expected:1\n");
        printf("Actual  :%d\n", result1);
        printf("\n");
    }

    {
        printf("Test 2\n");
        int result1 = get_quadrant(-3, 5);
        printf("Expected:2\n");
        printf("Actual  :%d\n", result1);
        printf("\n");
    }

    {
        printf("Test 4\n");
        int result1 = get_quadrant(3, -3);
        printf("Expected:4\n");
        printf("Actual  :%d\n", result1);
        printf("\n");
    }

    {
        printf("Test 5\n");
        int result1 = get_quadrant(0, 0);
        printf("Expected:0\n");
        printf("Actual  :%d\n", result1);
        printf("\n");
    }
}