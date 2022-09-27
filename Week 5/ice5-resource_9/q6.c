#include <stdio.h>

int get_num_unique(int n1, int n2, int n3) {
    if (n1 == n2 && n2 == n3) {
        return 1;
    }
    if (n1 != n2 && n1 != n3 && n2 != n3) {
        return 3;
    }
    return 2;
}

int main(void) {
    {
        printf("Test 1\n");
        int result = get_num_unique(1, 2, 3);
        printf("Expected:3\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 2\n");
        int result = get_num_unique(2, 2, 3);
        printf("Expected:2\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 3\n");
        int result = get_num_unique(3, 7, 3);
        printf("Expected:2\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 4\n");
        int result = get_num_unique(3, 7, 7);
        printf("Expected:2\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 5\n");
        int result = get_num_unique(9, 9, 9);
        printf("Expected:1\n");
        printf("Actual  :%d\n\n", result);
    }
}