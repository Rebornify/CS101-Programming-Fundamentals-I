#include <stdio.h>

int main(void) {
    double amount;
    printf("Enter amount:");
    scanf("%lf", &amount);
    printf("\n");

    int amount_in_c = amount * 100;

    int num_of_dollar = 0;
    if (amount_in_c >= 100) {
        while (amount_in_c >= 100) {
            num_of_dollar++;
            amount_in_c -= 100;
        }
        printf("Number of 1$: %d\n", num_of_dollar);
    }
    
    int num_of_50c = 0;
    if (amount_in_c >= 50) {
        while (amount_in_c >= 50) {
            num_of_50c++;
            amount_in_c -= 50;
        }
        printf("Number of 50c: %d\n", num_of_50c);
    }

    int num_of_20c = 0;
    if (amount_in_c >= 20) {
        while (amount_in_c >= 20) {
            num_of_20c++;
            amount_in_c -= 20;
        }
        printf("Number of 20c: %d\n", num_of_20c);
    }

    int num_of_10c = 0;
    if (amount_in_c >= 10) {
        while (amount_in_c >= 10) {
            num_of_10c++;
            amount_in_c -= 10;
        }
        printf("Number of 10c: %d\n", num_of_10c);
    }

    int num_of_5c = 0;
    if (amount_in_c >= 5) {
        while (amount_in_c >= 5) {
            num_of_5c++;
            amount_in_c -= 5;
        }
        printf("Number of 5c: %d\n", num_of_5c);
    }

    int num_of_1c = 0;
    if (amount_in_c >= 1) {
        while (amount_in_c >= 1) {
            num_of_1c++;
            amount_in_c -= 1;
        }
        printf("Number of 1c: %d\n", num_of_1c);
    }
}