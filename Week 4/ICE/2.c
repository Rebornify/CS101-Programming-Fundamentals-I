#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int n;
    printf("Enter number:");
    scanf("%d", &n);
    
    int largest = n;
    int smallest = n;

    while (n >= 0) {
        printf("Largest == %d. Smallest == %d.\n",largest, smallest);

        printf("Enter number:");
        scanf("%d", &n);

        if (n < largest) {
            smallest = n;
        } else if (n > smallest) {
            largest = n;
        }
    }
    printf("Bye!");
}