#include <stdio.h>
#include <ctype.h>

int main(void) {
    char letter;
    printf("Enter letter:");
    scanf("%c", &letter);

    while (isalpha(letter)) {
        switch (letter) {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            printf("vowel\n");
            break;
        default:
            printf("consonant\n");
        }
        printf("Enter letter:");
        scanf(" %c", &letter);
    }

    printf("Bye bye\n");
}