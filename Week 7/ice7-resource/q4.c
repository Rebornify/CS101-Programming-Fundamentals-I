#include <stdio.h>
#include <string.h>

void print_array(char string[]) {
    for (int i = 0; i < strlen(string); i++) {
        printf("%c", string[i]);
    }
    printf("\n");
}

void exchange_pairs(char s[]) {
    int len = strlen(s);
    for (int i  = 0; i < len - 1; i += 2) {
        char temp = s[i];
        s[i] = s[i + 1];
        s[i + 1] = temp;
    }
}


int main(void) {
    {
        char string[] = "abcdef";
        exchange_pairs(string);
        printf("Expected:badcfe\n");
        printf("Actual  :");
        print_array(string);
        printf("\n");
    }
    {
        char string[] = "abcdefg";
        exchange_pairs(string);
        printf("Expected:badcfeg\n");
        printf("Actual  :");
        print_array(string);
        printf("\n");
    }
    {
        char string[] = "a";
        exchange_pairs(string);
        printf("Expected:a\n");
        printf("Actual  :");
        print_array(string);
        printf("\n");
    }
}
