#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int flip_set(int num) {
    int result = 0;
    while (num != 0) {
        result *= 10;
        result += num % 10;
        num /= 10;
    }
    return result;
}

long flip_number(int num) {
    int sign = 1;

    if (num < 0) {
        num = -num;
        sign = -1;
    }

    if (num < 1000) {
        return sign * num;
    }

    int num_digits = log10(num) + 1;
    bool odd_digits = (num_digits % 2 != 0);

    int front = num / (int)pow(10, num_digits / 2);

    int middle = 0;

    if (odd_digits) {
        front = num / (int)pow(10, num_digits / 2 + 1);
        middle = num / (int)pow(10, num_digits / 2) % 10;
    }

    int back = num % (int)pow(10, num_digits / 2);

    int front_flipped = flip_set(front);
    int back_flipped = flip_set(back);

    while (back * 10 < pow(10, num_digits / 2)) {
        back_flipped *= 10;
        back *= 10;
    }

    if (odd_digits) {
        return sign * (front_flipped * pow(10, num_digits / 2 + 1) + middle
                * pow(10, num_digits / 2) + back_flipped);
    }

    return sign * (front_flipped * pow(10, num_digits / 2) + back_flipped);
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
        printf("Test %d\n", tc_num++);
        printf("Expected:1054\n");
        // 100 -> 001, 450 -> 054
        // thus 001054
        printf("Actual  :%ld\n", flip_number(100450));
        printf("\n");
    }
}
