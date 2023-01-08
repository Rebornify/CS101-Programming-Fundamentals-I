#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void repeat_twice(char original[], char two_times[]) {
    int n = strlen(original);
    for (int i = 0; i < n; i++) {
        two_times[i] = original[i];
        two_times[n + i] = original[i];
    }

    two_times[n * 2] = '\0';
}

void reverse(char arr[]) {
    int n = strlen(arr);
    int half_n = n / 2;

    for (int i = 0; i < half_n; i++) {
        char temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

bool is_same_arrangement(char first[], char second[]) {
    if (strlen(first) != strlen(second)) {
        return false;
    }

    char first_2x[strlen(first) * 2 + 1];
    repeat_twice(first, first_2x);

    bool is_same_direction = strstr(first_2x, second);

    reverse(first_2x);
    bool is_anti_direction = strstr(first_2x, second);

    return is_same_direction || is_anti_direction;
}

int main(void) {
    int tc_num = 1;
    {
        bool result = is_same_arrangement("ABCD", "DABC");
        printf("Test %d  :is_same_arrangement(\"ABCD\", \"DABC\")\n", tc_num++);
        printf("Expected:true\n");
        printf("Actual  :%s\n", result ? "true" : "false");
        printf("\n");
    }

    {
        bool result = is_same_arrangement("ARCDE", "CRAED");
        printf("Test %d  :is_same_arrangement(\"ARCDE\", \"CRAED\")\n", tc_num++);
        printf("Expected:true\n");
        printf("Actual  :%s\n", result ? "true" : "false");
        printf("\n");
    }

    {
        bool result = is_same_arrangement("ABCD", "CBDA");
        printf("Test %d  :is_same_arrangement(\"ABCD\", \"CBDA\")\n", tc_num++);
        printf("Expected:false\n");
        printf("Actual  :%s\n", result ? "true" : "false");
        printf("\n");
    }

    {
        bool result = is_same_arrangement("ABCD", "ABC");
        printf("Test %d  :is_same_arrangement(\"ABCD\", \"ABC\")\n", tc_num++);
        printf("Expected:false\n");
        printf("Actual  :%s\n", result ? "true" : "false");
        printf("\n");
    }

    {
        bool result = is_same_arrangement("ABC", "ABCD");
        printf("Test %d  :is_same_arrangement(\"ABC\", \"ABCD\")\n", tc_num++);
        printf("Expected:false\n");
        printf("Actual  :%s\n", result ? "true" : "false");
        printf("\n");
    }
}