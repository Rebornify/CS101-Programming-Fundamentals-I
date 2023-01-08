#include <stdio.h>
#include <string.h>

int total(char *arr) {
    char *temp = arr;

    int sum = 0;

    while (*arr != '\0') {
        while (*temp != '\0' && *temp != ' ') {
            temp++;
        }

        int value;
        sscanf(arr, "%d", &value);
        sum += value;

        if (*temp != '\0') {
            arr = temp + 1;
            temp = arr;
        } else {
            break;
        }
    }

    return sum;
}

int main(void) {
    {
        printf("Test 1\n");
        printf("Expected:6\n");
        int result = total("1 2 3");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 2\n");
        printf("Expected:3\n");
        int result = total("3");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 3\n");
        printf("Expected:1368\n");
        int result = total("11 123 1234");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}