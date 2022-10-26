#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sieve(int limit, int** result, int* n) {
    int count = 0;
    bool prime[limit + 1];
    for (int p = 2; p * p <= limit; p++) {
        if (prime[p] == true) {
            count++;
            for (int i = p * p; i <= limit; i++) {
                prime[i] = false;
            }
        }
    }

    int i = 0;
    int* temp = malloc(sizeof(int) * count);
    for (int p = 2; p <= limit; p++) {
        if(prime[p]) {
            temp[i++] = p;
        }
    }
    *result = temp;
    *n = count;
}

int main(void) {
    {
        int *result = NULL;
        int n = 0;
        sieve(30, &result, &n);
        printf("Expected:2 3 5 7 11 13 17 19 23 29\n");
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);
    }
}