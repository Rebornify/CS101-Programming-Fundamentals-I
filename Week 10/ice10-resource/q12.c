#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void scramble_sentence(char *orig, char *scrambled) {
    srand(time(NULL));

    char *orig_ptr = orig;
    bool contains_full_stop = false;
    while (*orig_ptr != '\0') {
        if (*orig_ptr == '.') {
            contains_full_stop = true;
        }
        orig_ptr++;
    } 

    int orig_len = strlen(orig);
    char temp[orig_len + 1];
    strcpy(temp, orig);

    char *token_ptr = strtok(temp, " .");
    while (token_ptr != NULL) {
        int tok_len = strlen(token_ptr);
        for (int i = tok_len - 2; i > 0; i--) {
            int j = (rand() % (tok_len - 2)) + 1;

            char temp1 = *(token_ptr + i);
            *(token_ptr + i) = *(token_ptr + j);
            token_ptr[j] = temp1;
        }

        while (*token_ptr != '\0') {
            *scrambled++ = *token_ptr++;
        }
        
        *scrambled++ = ' ';
        token_ptr = strtok(NULL, " .");
    }
    if (contains_full_stop) {
        *--scrambled = '.';
        scrambled++;
    }
    *scrambled = '\0';
}

int main(void) {
    {
        char orig[] = "This is a sentence with 7 tokens";
        char scrambled[35];
        scramble_sentence(orig, scrambled);
        printf("Test 1\n");
        printf("Original :%s\n", orig);
        printf("Scrambled:%s\n", scrambled);
        printf("\n");
    }

    {
        char orig[] = "C is peculiar in a lot of ways, but it, like many other successful things, has a certain unity of approach that stems from development in a small group.";
        char scrambled[155];
        scramble_sentence(orig, scrambled);
        printf("Test 2\n");
        printf("Original :%s\n", orig);
        printf("Scrambled:%s\n", scrambled);
    }

    // {char test[] = "this";
    // scramble(test);
    // printf("%s\n", test);
    // }

    //     {char test[] = "this";
    // scramble(test);
    // printf("%s\n", test);
    // }
    //     {char test[] = "this";
    // scramble(test);
    // printf("%s\n", test);
    // }
}