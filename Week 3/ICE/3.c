#include <stdio.h>

int main(void) {
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    int smallest = n;
    int largest = n;

    printf("Largest == %d. Smallest == %d.\n\n", smallest, largest);

    for (int i = 0; i < 4; i++) {
        printf("Enter n:");
        scanf("%d", &n);

        if (n < smallest) {
            smallest = n;
        }

        if (n > largest) {
            largest = n;
        }

        printf("Largest == %d. Smallest == %d\n\n", largest, smallest);
    }
}