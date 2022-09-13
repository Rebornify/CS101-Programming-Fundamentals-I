#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int start;
    printf("Enter start:");
    scanf("%d", &start);

    int end;
    printf("Enter end:");
    scanf("%d", &end);

    for (int i = start; i <= end; i++) {
        if (i < 2) {
            continue;
        }

        bool is_prime = true;
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                is_prime = !is_prime;
                break;
            }
        }

        if (is_prime) {
            printf("%d ", i);
        }
    }
}