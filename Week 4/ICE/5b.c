#include <stdio.h>
#include <stdbool.h>

int main(void) {
    char letter;

    bool is_valid = true;
    do {
        printf("Enter letter:");
        scanf(" %c", &letter);

        if (letter == 'a' || letter == 'A' || letter == 'e' || letter == 'E' || letter == 'i'
        || letter == 'I'|| letter == 'o' || letter == 'O' || letter == 'u' || letter == 'U') {
            printf("vowel\n");
        }
        else if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z')) {
            printf("consonent\n");
        }
        else {
            printf("Bye bye\n");
            is_valid = false;
        }
    } while (is_valid);
}