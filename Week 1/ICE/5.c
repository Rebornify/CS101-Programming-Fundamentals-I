#include <stdio.h>
#include <math.h>

int main(void) {
    double cap;
    printf("Enter capacity(mAh):");
    scanf("%lf", &cap);

    double volt;
    printf("Enter voltage(V):");
    scanf("%lf", &volt);

    printf("rated power: %d Wh\n", (int) round(cap / 1000 * volt));
}