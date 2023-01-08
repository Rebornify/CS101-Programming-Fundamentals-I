#include <stdio.h>

int main(void) {
    int males;
    printf("Enter num males:");
    scanf("%d", &males);

    int females;
    printf("Enter num females:");
    scanf("%d", &females);

    printf("Percentage(Females)= %.1lf%%\n", (double) females / (males + females) * 100);
}