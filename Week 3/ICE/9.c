#include <stdio.h>

int main(void) {
    int count;
    printf("Enter count of ascending sequence:");
    scanf("%d", &count);

    int start;
    printf("Enter the starting digit:");
    scanf("%d", &start);

    for (int i = 0; i < count; i++) {
        for (int j = start; j <= start + i; j++) {
            printf("%d", j);
        }
        printf(" ");
    }
    printf("\n");
}