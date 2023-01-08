#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sieve(int limit, int** result, int* n) {
    bool prime[limit + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= limit; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= limit; i += p) {
                prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= limit; p++) {
        if (prime[p] == true) {
            (*n)++;
        }
    }

    int* temp = malloc((*n) * sizeof(int));
    *result = temp;

    for (int p = 2; p <= limit; p++) {
        if (prime[p] == true) { 
            *temp++ = p;
        }
    }
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