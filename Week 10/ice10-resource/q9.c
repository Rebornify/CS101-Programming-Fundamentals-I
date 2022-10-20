#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_valid_length(char *password) {
    int len = strlen(password);
    if (len < 6 || len > 20) {
        return false;
    }
    return true;
}

bool contains_lower(char *password) {
    while (*password != '\0') {
        if (islower(*password)) {
            return true;
        }
        password++;
    }
    return false;
}

bool contains_upper(char *password) {
    while (*password != '\0') {
        if (isupper(*password)) {
            return true;
        }
        password++;
    }
    return false;
}

bool contains_number(char *password) {
    while (*password != '\0') {
        if (isdigit(*password)) {
            return true;
        }
        password++;
    }
    return false;
}

bool is_good_password(char *password) {
    return is_valid_length(password) && contains_lower(password) && contains_upper(password)
        && contains_number(password);
}

int main(void) {
    {
        char *password = "abc";
        printf("Test 1:%s\n", is_good_password(password) ? "Pass" : "Fail");
        printf("\n");
    }

    {
        char *password = "Abcdefghijklmnopqrst1234";
        printf("Test 2:%s\n", is_good_password(password) ? "Pass" : "Fail");
        printf("\n");
    }

    {
        char *password = "abcdefgh";
        printf("Test 3:%s\n", is_good_password(password) ? "Pass" : "Fail");
        printf("\n");
    }

    {
        char *password = "Abcdefgh";
        printf("Test 4:%s\n", is_good_password(password) ? "Pass" : "Fail");
        printf("\n");
    }

    {
        char *password = "ABCD1234";
        printf("Test 5:%s\n", is_good_password(password) ? "Pass" : "Fail");
        printf("\n");
    }

    {
        char *password = "abcd1234";
        printf("Test 6:%s\n", is_good_password(password) ? "Pass" : "Fail");
        printf("\n");
    }

    {
        char *password = "abcd123A";
        printf("Test 7:%s\n", is_good_password(password) ? "Pass" : "Fail");
        printf("\n");
    }
}
