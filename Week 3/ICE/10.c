#include <stdio.h>

int main(void) {
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    int t1 = 0;
    printf("%d ", t1);

    int t2 = 1;
    printf("%d ", t2);

    int nextTerm = t1 + t2;
    
    for (int i = 2; i < n; i++) {
        printf("%d ", nextTerm);
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
}