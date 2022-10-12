#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_num_vowels(char sentence[]) {
    int count = 0;
    for (int i = 0; i < strlen(sentence); i++) {
        char temp = tolower(sentence[i]);
        if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u') {
            count++;
        }
    }
    return count;
}

int main(void) {
    {
        printf("Test 1\n");
        int result = count_num_vowels("The brown fox jumps over the wall");
        printf("Expected:8\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 2\n");
        int result = count_num_vowels("Tht wld nt b pssbl. Nglsh wrds mst hv vwls.");
        printf("Expected:0\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 3\n");
        int result = count_num_vowels("");
        printf("Expected:0\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}
