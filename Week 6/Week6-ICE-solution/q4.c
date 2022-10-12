#include <stdio.h>
#include <math.h>

void print_expanded_form(int num) {    
    if (num <= 0) {
        printf("Invalid Input!\n");
        return;
    }

    // reverse the digit
    // n is to track the number of digits
    int reversed = 0;
    int n = 0;
    while (num > 0) {
        int digit = num % 10;
        num /= 10;

        reversed = reversed * 10 + digit;
        n++;
    }

    while (reversed > 10) {
        int digit = reversed % 10;
        int value = (int)(digit * pow(10, --n));
        if (value != 0) {
            printf("%d + ", value);
        }

        reversed /= 10;
    }

    int value = (int)(reversed * pow(10, --n));
    printf("%d ", value);
    printf("\n");
}

int main(void) {
    printf("Test 1\n");
    printf("Expected:");
    printf("10 + 2\n");
    printf("Actual  :");
    print_expanded_form(12);
    printf("\n");

    printf("Test 2\n");
    printf("Expected:");
    printf("100 + 20 + 3\n");
    printf("Actual  :");
    print_expanded_form(123);
    printf("\n");

    printf("Test 3\n");
    printf("Expected:");
    printf("100000 + 4\n");
    printf("Actual  :");
    print_expanded_form(100004);
    printf("\n");

    printf("Test 4\n");
    printf("Expected:");
    printf("Invalid Input!\n");
    printf("Actual  :");
    print_expanded_form(0);
    printf("\n");

    printf("Test 5\n");
    printf("Expected:");
    printf("Invalid Input!\n");
    printf("Actual  :");
    print_expanded_form(-163);
    printf("\n");

}