#include <stdbool.h>
#include <stdio.h>

bool is_anagram(char *word1, char *word2) {
    int freq1[26] = {0};
    while (*word1 != '\0') {
        if (*word1 >= 'a' && *word1 <= 'z') {
            freq1[*word1 - 'a']++;
        }
        word1++;
    }

    int freq2[26] = {0};
    while (*word2 != '\0') {
        if (*word2 >= 'a' && *word2 <= 'z') {
            freq2[*word2 - 'a']++;
        }
        word2++;
    }

    for(int i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            return false;
        }
    }

    return true;
}

int main(void) {
    {
        printf("Test 1:%s\n", is_anagram("listen", "silent") ? "Pass" : "Fail");
        printf("\n");
    }

    {
        printf("Test 2:%s\n", is_anagram("rail safety", "fairy tales") ? "Pass" : "Fail");
        printf("\n");
    }

    {
        printf("Test 3:%s\n", is_anagram("restful", "fluster") ? "Pass" : "Fail");
        printf("\n");
    }

    {
        printf("Test 4:%s\n", is_anagram("restfully", "fluttering") ? "Fail" : "Pass");
        printf("\n");
    }

    {
        printf("Test 5:%s\n", is_anagram("", "") ? "Pass" : "Fail");
        printf("\n");
    }
}
