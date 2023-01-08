#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(void) {
    srand(time(NULL));

    bool restart = false;

    do {
        int num = rand() % 100 + 1;

        int guess;
        int count = 0;
        bool is_correct = false;

        do {
            printf("Enter your guess (1 to 100) :");
            scanf("%d", &guess);

            count ++;

            char input;
            if (guess == num) {
                is_correct = true;

                printf("Congrats!\n\nYou guessed in %d attempts\n\nDo you want to play again?", count);
                scanf(" %c", &input);

                if (input == 'Y' || input == 'y') {
                    restart = true;
                    printf("\n");
                } else {
                    restart = false;
                }
            } else if (guess < num) {
                printf("Low! Try again\n\n");
            } else {
                printf("High! Try again\n\n");
            }
        } while (!is_correct);
    } while (restart);

    printf("\nBye!\n\n");
}