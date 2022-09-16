#include <stdio.h>

void print_calendar(int num_days, int first_sun) {
    printf("Su Mo Tu We Th Fr Sa\n");
    for (int i = 8 - first_sun; i > 0; i--) {
        if (i == 7) {
            break;
        }
        printf("   ");
    }

    for(int i = 1; i < first_sun; i++) {
        printf(" %d ", i);
    }

    printf("\n");

    for (int i = first_sun; i < num_days; i += 7) {
        for (int j = i; j < i + 7; j++) {
            if (j < 10) {
                printf(" %d ", j);
            } else if (j <= num_days) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main(void) {
    print_calendar(30, 2);
    printf("\n");
    print_calendar(31, 1);
    printf("\n");
    print_calendar(31, 7);
}