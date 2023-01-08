#include <stdio.h>
#include <ctype.h>

int main(void) {
    char letter;
    printf("Enter letter:");
    scanf("%c", &letter);

    while (isalpha(letter)) {
        letter = tolower(letter);

        if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter =='u' ) {
            printf("vowel\n");
        } else {
            printf("consonant\n");
        }

        printf("\n");
        printf("Enter letter:");
        scanf(" %c", &letter);
    }

    printf("Bye bye\n");
}