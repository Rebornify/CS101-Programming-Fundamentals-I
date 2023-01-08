#include <stdio.h>

int main(void) {
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    int largest = n;
    int smallest = n;

    printf("Largest so far == %d. Smallest so far == %d.\n", largest, smallest);

    for (int i = 0; i < 4; i++) {
        printf("Enter n:");
        scanf("%d", &n);

        if (n > largest) {
            largest = n;
        } else if (n < smallest) {
            smallest = n;
        }

        printf("Largest so far == %d. Smallest so far == %d.\n", largest, smallest);
    }
}