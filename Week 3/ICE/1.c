#include <stdio.h>
#include <math.h>

int main(void) {
    double deposit;
    printf("Initial Deposit (P) :");
    scanf("%lf", &deposit);

    double interest;
    printf("Annual Interest Rate (in %%, r) :");
    scanf("%lf", &interest);

    int frequency;
    printf("Annual Compound Frequency (1 to 12, n) :");
    scanf("%d", &frequency);

    int year;
    printf("Num years (t) :");
    scanf("%d", &year);

    double amount = deposit * pow((1 + (interest / 100) / frequency), frequency * year);

    printf("Amount after %d years is %.2lf\n", year, amount);
}