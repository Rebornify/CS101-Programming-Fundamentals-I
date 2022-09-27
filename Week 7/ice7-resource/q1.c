#include <stdio.h>

double average(int values[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += values[i];
    }
    return sum / n;
}
int main(void) {
    {
        printf("Test 1\n");
        int values[] = {1, 5, 13};
        double result = average(values, sizeof(values) / sizeof(int));
        printf("Expected:6.333333\n");
        printf("Actual  :%f\n", result);
        printf("\n");
    }

    {
        printf("Test 2\n");
        int values[] = {13, 1, 9, 5, 13, 75, 100};
        double result = average(values, sizeof(values) / sizeof(int));
        printf("Expected:30.857143\n");
        printf("Actual  :%f\n", result);
        printf("\n");
    }

    {
        printf("Test 3\n");
        int values[] = {0, 0, 0};
        double result = average(values, sizeof(values) / sizeof(int));
        printf("Expected:0.000000\n");
        printf("Actual  :%f\n", result);
        printf("\n");
    }
}
