/**
 * Name :
 * Email:
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_all_zeroes(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            return false;
        }
    }
    return true;
}

bool is_anagram(char* str1, char* str2) {
    if (strlen(str1) != strlen(str2)) {
        return false;
    }

    int len = strlen(str1);

    int freq[26] = {0};
    for (int i = 0; i < len; i++) {
        freq[str1[i] - 'a']++;
        freq[str2[i] - 'a']--;
    }

    return is_all_zeroes(freq, sizeof(freq) / sizeof(*freq));
}

void autocorrect_single_word(char* word_begin, char* word_end, int n, char* dict[]) {
    char original_word_end = *word_end;
    *word_end = '\0';

    for (int i = 0; i < n; i++) {
        if (is_anagram(word_begin, dict[i])) {
            strcpy(word_begin, dict[i]);
            *word_end = original_word_end;
            return;
        }
    }

    *word_end = original_word_end;
}

void autocorrect(char *sentence, int n, char *dict[]) {
    char* word_end = sentence;

    while (*word_end != '\0') {
        while (*word_end != '\0' && *word_end != ' ') {
            word_end++;
        }

        autocorrect_single_word(sentence, word_end, n, dict);

        if (*word_end != '\0') {
            sentence = word_end + 1;
            word_end = sentence;
        }
    }
}

int main(void) {
    int test_id = 0;

    {
        char input[] = "nma";
        char expected[] = "man";
        char *dict[] = {"not", "hot", "quick", "math", "likes",
                        "wolverine", "drinks", "soju", "pizza",
                        "wingstop", "iron", "man", "eats", "potato"};
        // Test 1
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Input:    %s\n", input);
        printf("Expected: %s\n", expected);
        autocorrect(input, sizeof(dict) / sizeof(char *), dict);
        printf("Actual:   %s\n", input);
        printf("\n");
    }

    {
        char input[] = "winelover likse zzipa";
        char expected[] = "wolverine likes pizza";
        char *dict[] = {"not", "hot", "quick", "math", "likes",
                        "wolverine", "drinks", "soju", "pizza",
                        "wingstop", "iron", "man", "eats", "potato"};
        // Test 2
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Input:    %s\n", input);
        printf("Expected: %s\n", expected);
        autocorrect(input, sizeof(dict) / sizeof(char *), dict);
        printf("Actual:   %s\n", input);
        printf("\n");
    }

    {
        char input[] = "rino man lskie stopwing";
        char expected[] = "iron man likes wingstop";
        char *dict[] = {"not", "hot", "quick", "math", "likes",
                        "wolverine", "drinks", "soju", "pizza",
                        "wingstop", "iron", "nori", "man", "eats", "potato"};

        // Test 3
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Input:    %s\n", input);
        printf("Expected: %s\n", expected);
        autocorrect(input, sizeof(dict) / sizeof(char *), dict);
        printf("Actual:   %s\n", input);
        printf("\n");
    }

    {
        char input[] = "pootato drinks juso";
        char expected[] = "pootato drinks soju";
        char *dict[] = {"not", "hot", "quick", "math", "likes",
                        "wolverine", "drinks", "soju", "pizza",
                        "wingstop", "iron", "man", "eats", "potato"};
        // Test 4
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Input:    %s\n", input);
        printf("Expected: %s\n", expected);
        autocorrect(input, sizeof(dict) / sizeof(char *), dict);
        printf("Actual:   %s\n", input);
        printf("\n");
    }

    {
        char input[] = "halp y u do dis";
        char expected[] = "halp y u do dis";
        char *dict[] = {"not", "hot", "quick", "math", "likes",
                        "wolverine", "drinks", "soju", "pizza", "wingstop", "iron", "man", "eats", "potato"};
        // Test 5
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Input:    %s\n", input);
        printf("Expected: %s\n", expected);
        autocorrect(input, sizeof(dict) / sizeof(char *), dict);
        printf("Actual:   %s\n", input);
        printf("\n");
    }
}
