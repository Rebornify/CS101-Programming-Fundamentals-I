#include <stdio.h>
#include <ctype.h>

int main(void) {
    char letter;
    printf("Enter letter:");
    scanf("%c", &letter);

    while (isalpha(letter)) {
        letter = tolower(letter);

        switch (letter) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                printf("vowel\n");
                break;
            default:
                printf("consonant\n");
        }

        printf("\n");
        printf("Enter letter:");
        scanf(" %c", &letter);
    }

    printf("Bye bye\n");
}