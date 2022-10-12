#include <stdio.h>

int convert(double temp, char scale) {
    if (scale == 'C') {
        return (int)(temp * 9.0 / 5 + 32);
    }
    return (int)((temp - 32) * 5.0 / 9);
}

int main(void) {
    int tc_num = 1;
    {
        // TC 1
        int temp = 30;
        char scale = 'C';
        printf("Test %d: convert(%d, %c)\n", tc_num++, temp, scale);
        printf("Expected:86\n");
        printf("Actual  :%d\n", convert(temp, scale));
        printf("\n");
    }

    {
        // TC 2
        int temp = 50;
        char scale = 'F';
        printf("Test %d: convert(%d, %c)\n", tc_num++, temp, scale);
        printf("Expected:10\n");
        printf("Actual  :%d\n", convert(temp, scale));
        printf("\n");
    }

    {
        // TC 3
        int temp = -55;
        char scale = 'C';
        printf("Test %d: convert(%d, %c)\n", tc_num++, temp, scale);
        printf("Expected:-67\n");
        printf("Actual  :%d\n", convert(temp, scale));
        printf("\n");
    }

}