#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_all_zeroes(int array[], int len) {
    for (int i = 0; i < len; i++) {
        if (array[i] != 0) {
            return false;
        }
    }

    return true;
}

bool is_anagram(const char *string1, const char *string2) {
    if (strlen(string1) != strlen(string2)) {
        return false;
    }

    int freq[27] = {0};
    for (int i = 0; i < strlen(string1); i++) {
        freq[string1[i] - 'a']++;
        freq[string2[i] - 'a']--;
    }

    return is_all_zeroes(freq, sizeof(freq) / sizeof(*freq));
}

void autocorrect_single_word(char *word_begin, char *word_end, int n, char *dict[]) {
    char original_word_end = *word_end;

    *word_end = '\0';
    // printf("word_begin = %s\n", word_begin);
    for (int i = 0; i < n; i++) {
        if (is_anagram(word_begin, dict[i])) {
            strcpy(word_begin, dict[i]);
            // printf("word_begin = %s\n", word_begin);
            *word_end = original_word_end;
            return;
        }
    }

    *word_end = original_word_end;
    return;
}

void autocorrect(char *sentence, int n, char *dict[]) {
    char *word_begin = sentence;
    char *word_end = sentence;

    while (*word_begin && *word_end) {
        while (*word_end && *word_end != ' ') {
            word_end++;
        }
        // printf("*word_begin = %c, *word_end = %c\n", *word_begin, *word_end);
        autocorrect_single_word(word_begin, word_end, n, dict);
        // printf("sentence = %s\n", sentence);
        if (*word_end) {
            word_begin = word_end + 1;
            word_end = word_begin;
        }
    }
}

int main(void) {
    int test_id = 0;

    {
        char input[] = "nma";
        char expected[] = "man";
        char *dict[] = {"not", "hot", "quick", "math", "likes",
                        "wolverine", "drinks", "soju", "pizza", "wingstop", "iron", "man", "eats", "potato"};

        // Test 1
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Input:    %s\n", input);
        printf("Expected: %s\n", expected);
        autocorrect(input, sizeof(dict)/sizeof(char *), dict);
        printf("Actual:   %s\n", input);
        printf("\n");
    }

    {
        char input[] = "winelover likse zzipa";
        char expected[] = "wolverine likes pizza";
        char *dict[] = {"not", "hot", "quick", "math", "likes",
                        "wolverine", "drinks", "soju", "pizza", "wingstop", "iron", "man", "eats", "potato"};

        // Test 2
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Input:    %s\n", input);
        printf("Expected: %s\n", expected);
        autocorrect(input, sizeof(dict)/sizeof(char *), dict);
        printf("Actual:   %s\n", input);
        printf("\n");
    }

    {
        char input[] = "rino man lskie stopwing";
        char expected[] = "iron man likes wingstop";
        char *dict[] = {"not", "hot", "quick", "math", "likes",
                        "wolverine", "drinks", "soju", "pizza", "wingstop", "iron", "nori", "man", "eats", "potato"};

        // Test 3
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Input:    %s\n", input);
        printf("Expected: %s\n", expected);
        autocorrect(input, sizeof(dict)/sizeof(char *), dict);
        printf("Actual:   %s\n", input);
        printf("\n");
    }

    {
        char input[] = "pootato drinks juso";
        char expected[] = "pootato drinks soju";
        char *dict[] = {"not", "hot", "quick", "math", "likes",
                        "wolverine", "drinks", "soju", "pizza", "wingstop", "iron", "man", "eats", "potato"};
        // Test 4
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Input:    %s\n", input);
        printf("Expected: %s\n", expected);
        autocorrect(input, sizeof(dict)/sizeof(char *), dict);
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
        autocorrect(input, sizeof(dict)/sizeof(char *), dict);
        printf("Actual:   %s\n", input);
        printf("\n");
    }


}
