#include <stdio.h>

int main(void) {
    int month;
    printf("Enter month as a number:");
    scanf("%d", &month);

    if (month < 1 || month > 12) {
        printf("Enter a number between 1 and 12 only.\n");
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        printf("There are 30 days in this month.\n");
    } else if (month == 2) {
        printf("There are 28 days in this month.\n");
    } else {
        printf("There are 31 days in this month.\n");
    }
}