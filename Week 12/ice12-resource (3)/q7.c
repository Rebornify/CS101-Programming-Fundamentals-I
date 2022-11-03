#include <stdio.h>
#include <string.h>

void print_dancing_string_row(char *sentence, int x, int y) {
    int len = strlen(sentence);

    printf("|");
    for (int i = 0; i < len; i++) {
        if (i % x == y) {
            printf("%c", sentence[i]);
        } else {
            printf(" ");
        }
    }
    printf("|\n");
}

void print_dancing_string(char *sentence, char start) {
    if (start == 'T') {
        print_dancing_string_row(sentence, 4, 0);
        print_dancing_string_row(sentence, 2, 1);
        print_dancing_string_row(sentence, 4, 2);
    } else if (start == 'M') {
        print_dancing_string_row(sentence, 4, 1);
        print_dancing_string_row(sentence, 2, 0);
        print_dancing_string_row(sentence, 4, 3);
    } else {
        print_dancing_string_row(sentence, 4, 2);
        print_dancing_string_row(sentence, 2, 1);
        print_dancing_string_row(sentence, 4, 0);
    }
}

int main(void) {
    {
        printf("Test 1\n");
        printf("Expected:\n");
        printf("|a|\n");
        printf("| |\n");
        printf("| |\n");
        printf("Actual  :\n");
        print_dancing_string("a", 'T');
        printf("\n");
    }

    {
        printf("Test 2\n");
        printf("Expected:\n");
        printf("|a   e   i|\n");
        printf("| b d f h |\n");
        printf("|  c   g  |\n");
        printf("Actual  :\n");
        print_dancing_string("abcdefghi", 'T');
        printf("\n");
    }

    {
        printf("Test 3\n");
        printf("Expected:\n");
        printf("| b   f   |\n");
        printf("|a c e g i|\n");
        printf("|   d   h |\n");
        printf("Actual  :\n");
        print_dancing_string("abcdefghi", 'M');
        printf("\n");
    }

    {
        printf("Test 4\n");
        printf("Expected:\n");
        printf("|  c   g  |\n");
        printf("| b d f h |\n");
        printf("|a   e   i|\n");
        printf("Actual  :\n");
        print_dancing_string("abcdefghi", 'B');
        printf("\n");
    }

    {
        printf("Test 5\n");
        printf("Expected:\n");
        printf("||\n");
        printf("||\n");
        printf("||\n");
        printf("Actual  :\n");
        print_dancing_string("", 'B');
        printf("\n");
    }
}