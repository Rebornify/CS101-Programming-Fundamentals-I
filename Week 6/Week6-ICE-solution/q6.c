#include <stdio.h>
long int factorial(long int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result = result * i;
    }
    
    return result;  
}

long n_choose_k(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

void print_pascal(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%ld ", n_choose_k(i, j));
        }
        printf("\n");
    }
}

int main(void) {
    printf("Test 1\n");
    printf("Expected:\n");
    printf("1 \n");
    printf("1 1\n"); 
    printf("1 2 1\n");
    printf("1 3 3 1\n");
    printf("1 4 6 4 1\n");
    printf("Actual:\n");
    print_pascal(5);
    printf("\n");
    
    printf("Test 2\n");
    printf("Expected:\n");
    printf("1\n");
    printf("1 1\n"); 
    printf("1 2 1\n"); 
    printf("1 3 3 1\n");
    printf("1 4 6 4 1\n");
    printf("1 5 10 10 5 1\n");
    printf("1 6 15 20 15 6 1\n");
    printf("1 7 21 35 35 21 7 1\n");
    printf("1 8 28 56 70 56 28 8 1\n");
    printf("1 9 36 84 126 126 84 36 9 1\n");
    printf("Actual:\n");
    print_pascal(10);
}
