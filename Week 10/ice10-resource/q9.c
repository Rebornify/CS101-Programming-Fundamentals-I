#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>



int main(void) {
    {
        char *password = "abc";
        printf("Test 1:%s\n", is_good_password(password) ? "Fail" : "Pass");
        printf("\n");
    }

    {
        char *password = "Abcdefghijklmnopqrst1234";
        printf("Test 2:%s\n", is_good_password(password) ? "Fail" : "Pass");
        printf("\n");
    }

    {
        char *password = "abcdefgh";
        printf("Test 3:%s\n", is_good_password(password) ? "Fail" : "Pass");
        printf("\n");
    }

    {
        char *password = "Abcdefgh";
        printf("Test 4:%s\n", is_good_password(password) ? "Fail" : "Pass");
        printf("\n");
    }

    {
        char *password = "ABCD1234";
        printf("Test 5:%s\n", is_good_password(password) ? "Fail" : "Pass");
        printf("\n");
    }

    {
        char *password = "abcd1234";
        printf("Test 6:%s\n", is_good_password(password) ? "Fail" : "Pass");
        printf("\n");
    }

    {
        char *password = "abcd123A";
        printf("Test 7:%s\n", is_good_password(password) ? "Pass" : "Fail");
        printf("\n");
    }
}
