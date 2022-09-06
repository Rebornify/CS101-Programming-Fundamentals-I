#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    
    int smallest = n;
    int largest = n;

    while (n >= 0) {
        printf("Largest == %d. Smallest == %d.\n",largest, smallest);

        printf("Enter n:");
        scanf("%d", &n);

        if (n < largest) {
            smallest = n;
        }
        else if (n > smallest) {
            largest = n;
        }
    }
    printf("Bye!");
}