#include <stdio.h>

int main(void) {
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    long sum = 0;
    for (int i = 7; i <= n ; i += 7) {
        if (i % 7 == 0) {
            sum += i;
        }
    }
    printf("%ld\n", sum);
}