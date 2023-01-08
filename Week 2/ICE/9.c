#include <stdio.h>

int main(void) {
    double sales;
    printf("Enter the amount of monthly sales($):");
    scanf("%lf", &sales);

    double comm;
    if (sales < 10000) {
        comm = sales * 0.05;
        printf("Commission rate for the monthly sale of $%.2lf is 5%%\n", sales);
    } else if (sales < 15000) {
        comm = sales * 0.1;
        printf("Commission rate for the monthly sale of $%.2lf is 10%%\n", sales);
    } else if (sales < 18000) {
        comm = sales * 0.15;
        printf("Commission rate for the monthly sale of $%.2lf is 15%%\n", sales);
    } else {
        comm = sales * 0.18;
        printf("Commission rate for the monthly sale of $%.2lf is 18%%\n", sales);
    }
    
    printf("The monthly pay for the salesperson is $%.2lf\n", 2000 + comm);
}