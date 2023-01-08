#include <stdio.h>
#include <math.h>

int main(void) {
    int P;
    printf("Intitial Deposit(P):");
    scanf("%d", &P);

    double r;
    printf("Annual Interest Rate (in %%, r):");
    scanf("%lf", &r);

    int n;
    printf("Annual Compound Frequency (1 to 12, n):");
    scanf("%d", &n);

    int t;
    printf("Num years (t):");
    scanf("%d", &t);

    double A = P * pow((1 + r / 100 / n), n * t);

    printf("Amount after 5 years is %.2lf\n", A);
}