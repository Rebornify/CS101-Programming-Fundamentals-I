#include <stdio.h>

int main(void) {
    double weight;
    printf("Enter weight(kg):");
    scanf("%lf", &weight);

    double height;
    printf("Enter height(m):");
    scanf("%lf", &height);

    printf("BMI is %lf\n", weight / (height * height));
}