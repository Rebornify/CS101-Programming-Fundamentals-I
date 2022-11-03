#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char get_highest_occurring_character(char *sentence) {
    int len = strlen(sentence);
    if (len == 0) {
        return '\0';
    }

    int count[26] = {0};
    for (int i = 0; i < len; i++) {
        char temp = sentence[i];
        if (isalpha(temp)) {
            if (isupper(temp)) {
                temp = tolower(temp);
            }
            count[temp - 'a']++;
        }
    }

    int highest = count[0];
    int index = 0;
    
    for (int i = 1; i < 26; i++) {
        if (count[i] > highest) {
            highest = count[i];
            index = i;
        }
    }
    return 'a' + index;
}

int main(void) {
    int tc_num  = 1;
    {
        char result = get_highest_occurring_character("abbba");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:b\n");
        printf("Actual  :%c\n", result);
        printf("\n");
    }

    {
        char result = get_highest_occurring_character("Apple ACE Car code coke");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:c\n");
        printf("Actual  :%c\n", result);
        printf("\n");
    }

    {
        char result = get_highest_occurring_character("");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:True\n");
        printf("Actual  :%s\n", result == '\0' ? "True" : "False");
        printf("\n");
    }
}