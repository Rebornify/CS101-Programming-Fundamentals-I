#include <stdio.h>

int main(void) {
    double income;
    printf("Enter personal income :");
    scanf("%lf", &income);

    double tax;
    if (income <= 20000) {
        tax = 0;
    } else if (income <= 30000) {
        tax = 0.02 * (income - 20000);
    } else if (income <= 40000) {
        tax = 200 + 0.035 * (income - 30000);
    } else if (income <= 80000) {
        tax = 550 + 0.07 * (income - 40000);
    } else if (income <= 120000) {
        tax = 3350 + 0.115 * (income - 80000);
    } else if (income <= 160000) {
        tax = 7790 + 0.15 * (income - 120000);
    } else if (income <= 200000) {
        tax = 13950 + 0.18 * (income - 160000);
    } else {
        tax = 21150 + 0.2 * (income - 200000);
    }
    
    printf("Tax payable: $%.2lf\n", tax);
}