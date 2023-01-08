#include <stdio.h>

void encode(char *plaintext, char *ciphertext, int s) {
    while (*plaintext != '\0') {
        if (*plaintext >= 'A' && *plaintext <= 'Z') {
            *ciphertext++ = (*plaintext + s - 'A') % 26 + 'A';
        } else if (*plaintext >= 'a' && *plaintext <= 'z') {
            *ciphertext++ = (*plaintext + s - 'a') % 26 + 'a';
        } else {
            *ciphertext++ = *plaintext;
        }
        plaintext++;
    }
    *ciphertext = '\0';
}

void decode(char *plaintext, char *ciphertext, int s) {
    while (*ciphertext != '\0') {
        if (*ciphertext >= 'A' && *ciphertext <= 'Z') {
            *plaintext++ = *ciphertext - s - 'A' % 26 < 0 ?
                'Z' + 1 + (*ciphertext - s - 'A') % 26 : (*ciphertext - s - 'A') % 26 + 'A';
        } else if (*ciphertext >= 'a' && *ciphertext <= 'z') {
            *plaintext++ = (*ciphertext - s - 'a') % 26 < 0 ?
                'z' + 1 + (*ciphertext - s - 'a') % 26 : (*ciphertext - s - 'a') % 26 + 'a';
        } else {
            *plaintext++ = *ciphertext;
        }
        ciphertext++;
    }
    *plaintext = '\0';
}

int main(void) {
    {
        char *plaintext = "abc";
        char ciphertext[4] = {0};
        encode(plaintext, ciphertext, 1);
        printf("Test 1\n");
        printf("Expected:bcd\n");
        printf("Actual  :%s\n", ciphertext);
        printf("\n");
    }

    {
        char *plaintext = "abc";
        char ciphertext[4] = {0};
        encode(plaintext, ciphertext, 27);
        printf("Test 2\n");
        printf("Expected:bcd\n");
        printf("Actual  :%s\n", ciphertext);
        printf("\n");
    }

    {
        char *plaintext = "apples and oranges. Which do you prefer?";
        char ciphertext[45] = {0};
        encode(plaintext, ciphertext, 13);
        printf("Test 3\n");
        printf("Expected:nccyrf naq benatrf. Juvpu qb lbh cersre?\n");
        printf("Actual  :%s\n", ciphertext);
        printf("\n");
    }

    {
        char *plaintext = "###";
        char ciphertext[4] = {0};
        encode(plaintext, ciphertext, 13);
        printf("Test 4\n");
        printf("Expected:###\n");
        printf("Actual  :%s\n", ciphertext);
        printf("\n");
    }

    // ------
    {
        char *ciphertext = "bcd";
        char plaintext[4] = {0};
        decode(plaintext, ciphertext, 1);
        printf("Test 5\n");
        printf("Expected:abc\n");
        printf("Actual  :%s\n", plaintext);
        printf("\n");
    }

    {
        char *ciphertext = "bcd";
        char plaintext[4] = {0};
        decode(plaintext, ciphertext, 27);
        printf("Test 6\n");
        printf("Expected:abc\n");
        printf("Actual  :%s\n", plaintext);
        printf("\n");
    }

    {
        char *ciphertext = "P gur yvtug ng gur raq bs gur ghaary";
        char plaintext[40] = {0};
        decode(plaintext, ciphertext, 13);
        printf("Test 7\n");
        printf("Expected:C the light at the end of the tunnel\n");
        printf("Actual  :%s\n", plaintext);
        printf("\n");
    }

    {
        char *ciphertext = "abc 123";
        char plaintext[40] = {0};
        decode(plaintext, ciphertext, 26);
        printf("Test 7\n");
        printf("Expected:abc 123\n");
        printf("Actual  :%s\n", plaintext);
        printf("\n");
    }
}