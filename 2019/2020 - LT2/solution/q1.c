#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find_and_replace(char *target, const char *find, const char substitute) {
    for (int i = 0; i < strlen(target); i++) {
        for (int j = 0; j < strlen(find); j++) {
            if (target[i] == find[j]) {
                target[i] = substitute;
            }
        }
    }
}

int main(void) {
    int test_id = 0;

    {
        char input[] = "pootato";
        char *find = "a";
        char substitute = 'o';
        char expected[] = "poototo";

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Find:       ");
        printf("'%c'", find[0]);
        for (int i = 1; i < strlen(find); i++) {
            printf(", '%c'", find[i]);
        }
        printf("\n");
        printf("Substitute: '%c'\n", substitute);
        printf("Input:      %s\n", input);
        printf("Expected:   %s\n", expected);
        find_and_replace(input, find, substitute);
        printf("Actual:     %s\n", input);
        printf("\n");
    }

    {
        char input[] = "i love you 3000";
        char *find = "30";
        char substitute = '9';
        char expected[] = "i love you 9999";

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Find:       ");
        printf("'%c'", find[0]);
        for (int i = 1; i < strlen(find); i++) {
            printf(", '%c'", find[i]);
        }
        printf("\n");
        printf("Substitute: '%c'\n", substitute);
        printf("Input:      %s\n", input);
        printf("Expected:   %s\n", expected);
        find_and_replace(input, find, substitute);
        printf("Actual:     %s\n", input);
        printf("\n");
    }

    {
        char input[] = "code";
        char *find = "code";
        char substitute = 'z';
        char expected[] = "zzzz";

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Find:       ");
        printf("'%c'", find[0]);
        for (int i = 1; i < strlen(find); i++) {
            printf(", '%c'", find[i]);
        }
        printf("\n");
        printf("Substitute: '%c'\n", substitute);
        printf("Input:      %s\n", input);
        printf("Expected:   %s\n", expected);
        find_and_replace(input, find, substitute);
        printf("Actual:     %s\n", input);
        printf("\n");
    }

    {
        char input[] = "I love cooking, my korkor, and my dog";
        char *find = ",";
        char substitute = ' ';
        char expected[] = "I love cooking  my korkor  and my dog";

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Find:       ");
        printf("'%c'", find[0]);
        for (int i = 1; i < strlen(find); i++) {
            printf(", '%c'", find[i]);
        }
        printf("\n");
        printf("Substitute: '%c'\n", substitute);
        printf("Input:      %s\n", input);
        printf("Expected:   %s\n", expected);
        find_and_replace(input, find, substitute);
        printf("Actual:     %s\n", input);
        printf("\n");
    }

    {
        char input[] = "Courage! Do not be afraid! Just a few questions left!";
        char *find = "1234567890";
        char substitute = 'Z';
        char expected[] = "Courage! Do not be afraid! Just a few questions left!";

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Find:       ");
        printf("'%c'", find[0]);
        for (int i = 1; i < strlen(find); i++) {
            printf(", '%c'", find[i]);
        }
        printf("\n");
        printf("Substitute: '%c'\n", substitute);
        printf("Input:      %s\n", input);
        printf("Expected:   %s\n", expected);
        find_and_replace(input, find, substitute);
        printf("Actual:     %s\n", input);
        printf("\n");
    }
}
