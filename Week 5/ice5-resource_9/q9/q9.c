#include <stdio.h>

int main(void) {
    int x;
    printf("Enter x:");
    scanf("%d", &x);

    int y;
    printf("Enter y:");
    scanf("%d", &y);
    
    printf("%d + %d = %d\n", x, y, add(x, y));
}