#include <stdio.h>
#include <ctype.h>

int main(void) {
    char gender;
    printf("Enter your gender (M or F) :");
    scanf("%c", &gender);
    gender = toupper(gender);

    int age;
    printf("Enter your age :");
    scanf("%d", &age);

    double premium;
    if (age < 25) {
        premium = gender == 'M' ? 20.5 : 30.6;
    } else if (age < 30) {
        premium = gender == 'M' ? 30.4 : 50.7;
    } else if (age < 65) {
        premium = gender == 'M' ? 60.7 : 99.8;
    } else {
        premium = gender == 'M' ? 70.7 : 120.3;
    }

    printf("Your premium is $%.2lf\n", premium);
}