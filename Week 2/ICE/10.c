#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int num1 = rand() % 9 + 1;
    int num2 = rand() % 9 + 1;
    int num3 = rand() % 9 + 1;

    printf("Press <enter> key to start\n");
    getchar();

    printf("*****************\n");
    printf("** %d ** %d ** %d **\n", num1, num2, num3);
    printf("*****************\n");

    if (num1 == num2 && num1 == num3) {
        printf("** Jackpot!! **\n");
    } else if (num1 == num2 || num1 == num3 || num2 == num3) {
        printf("** 2 of a kind **\n");
    } else {
        printf("** Try again! **\n");
    }
}