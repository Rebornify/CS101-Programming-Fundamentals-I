#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TC1 1
#define TC2 1
#define TC3 1
#define TC4 1
#define TC5 1

#if SINGLE_TC == 1
#define TC1 1
#define TC2 0
#define TC3 0
#define TC4 0
#define TC5 0
#endif

#if SINGLE_TC == 2
#define TC1 0
#define TC2 1
#define TC3 0
#define TC4 0
#define TC5 0
#endif

#if SINGLE_TC == 3
#define TC1 0
#define TC2 0
#define TC3 1
#define TC4 0
#define TC5 0
#endif

#if SINGLE_TC == 4
#define TC1 0
#define TC2 0
#define TC3 0
#define TC4 1
#define TC5 0
#endif

#if SINGLE_TC == 5
#define TC1 0
#define TC2 0
#define TC3 0
#define TC4 0
#define TC5 1
#endif

void repeat_twice__(char original[], char twoTimes[]) {
    int n = strlen(original);
    for (int i = 0; i < n; i++) {
        twoTimes[i] = original[i];
        twoTimes[n + i] = original[i];
    }
    twoTimes[n*2] = '\0';
}

void reverse__(char arr[]) {
    int n = strlen(arr);
    int half_n = n/2;

    for (int i = 0; i < half_n; i++) {
        char temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}
bool expected_is_same_arrangement(char first[], char second[]) {
    if (strlen(first) != strlen(second)) {
        return false;
    }

    char first_2x[strlen(first) * 2 + 1];
    repeat_twice__(first, first_2x);

    bool is_same_direction = strstr(first_2x, second);


    reverse__(first_2x);
    bool is_anti_direction = strstr(first_2x, second);

    return is_same_direction || is_anti_direction;
}
int main(void) {
    int tc_num = 1;
    if (0) {
        bool result = is_same_arrangement("ABCD", "DABC");
        printf("Test %d  :is_same_arrangement(\"ABCD\", \"DABC\")\n", tc_num++);
        printf("Expected:true\n");
        printf("Actual  :%s\n", result ? "true" : "false");
        printf("\n");
    }

    if (0) {
        bool result = is_same_arrangement("ARCDE", "CRAED");
        printf("Test %d  :is_same_arrangement(\"ARCDE\", \"CRAED\")\n", tc_num++);
        printf("Expected:true\n");
        printf("Actual  :%s\n", result ? "true" : "false");
        printf("\n");
    }

    if (0) {
        bool result = is_same_arrangement("ABCD", "CBDA");
        printf("Test %d  :is_same_arrangement(\"ABCD\", \"CBDA\")\n", tc_num++);
        printf("Expected:false\n");
        printf("Actual  :%s\n", result ? "true" : "false");
        printf("\n");
    }

    if (0) {
        bool result = is_same_arrangement("ABCD", "ABC");
        printf("Test %d  :is_same_arrangement(\"ABCD\", \"ABC\")\n", tc_num++);
        printf("Expected:false\n");
        printf("Actual  :%s\n", result ? "true" : "false");
        printf("\n");
    }

    if (0) {
        bool result = is_same_arrangement("ABC", "ABCD");
        printf("Test %d  :is_same_arrangement(\"ABC\", \"ABCD\")\n", tc_num++);
        printf("Expected:false\n");
        printf("Actual  :%s\n", result ? "true" : "false");
        printf("\n");
    }


    /***   Secret test cases   ***/

    // Validity check: weed out functions that return the same value all the time
    if (0) {
        bool result[4] = { -1 };

        {
            char* input1 = "abcdefghijklmnopqrstuvwxyz0123456789";
            char* input2 = "9876543210zyxwvutsrqponmlkjihgfedcba";
            result[0] = is_same_arrangement(input1, input2);
            printf("result[0] = %d\n", result[0]);
        }

        {
            char* input1 = "abcdefghijklmnopqrstuvwxyz0123456789";
            char* input2 = "0123456789abcdefghijklmnopqrstuvwxyz";
            result[1] = is_same_arrangement(input1, input2);
            printf("result[1] = %d\n", result[1]);
        }

        {
            char* input1 = "a";
            char* input2 = "b";
            result[2] = is_same_arrangement(input1, input2);
            printf("result[2] = %d\n", result[2]);
        }

        {
            char* input1 = "ABCDEFGHIJKLMNOPQRST";
            char* input2 = "GHIJKLMN0PQRSTUVWXYZ";
            result[3] = is_same_arrangement(input1, input2);
            printf("result[3] = %d\n", result[3]);
        }

        if (result[0] == result[1] && result[0] == result[2] && result[0] == result[3]) {
            printf("%s,invalid\n\n", __FILE__);
        } else {
            printf("%s,valid\n\n", __FILE__);
        }
        // return;
    }


    if (TC1) {
        tc_num = 1;
        double score = 1;

        char* input1 = "abcdefghijklmnopqrstuvwxyz0123456789";
        char* input2 = "9876543210zyxwvutsrqponmlkjihgfedcba";

        printf("Test %d  : expected_is_same_arrangement(%s, %s))\n", tc_num, input1, input2);
        printf("Expected : %s\n", expected_is_same_arrangement(input1, input2) ? "true" : "false");
        printf("Actual   : %s\n", is_same_arrangement(input1, input2) ? "true" : "false");
        printf("\n");
        
        if (((is_same_arrangement(input1, input2) == true) || (is_same_arrangement(input1, input2) == false)) &&
            expected_is_same_arrangement(input1, input2) == is_same_arrangement(input1, input2)) {
        } else {
            score = 0;
        }
        printf("%s,%d,%.2f\n\n", __FILE__, tc_num, score);

    }

    if (TC2) {
        tc_num = 2;
        double score = 1;

        char* input1 = "abcdefghijklmnopqrstuvwxyz0123456789";
        char* input2 = "0123456789abcdefghijklmnopqrstuvwxyz";

        printf("Test %d  : expected_is_same_arrangement(%s, %s))\n", tc_num, input1, input2);
        printf("Expected : %s\n", expected_is_same_arrangement(input1, input2) ? "true" : "false");
        printf("Actual   : %s\n", is_same_arrangement(input1, input2) ? "true" : "false");
        printf("\n");
        
        if (((is_same_arrangement(input1, input2) == true) || (is_same_arrangement(input1, input2) == false)) &&
            expected_is_same_arrangement(input1, input2) == is_same_arrangement(input1, input2)) {
        } else {
            score = 0;
        }
        printf("%s,%d,%.2f\n\n", __FILE__, tc_num, score);
    }

    if (TC3) {
        tc_num = 3;
        double score = 1;

        char* input1 = "a";
        char* input2 = "b";

        printf("Test %d  : expected_is_same_arrangement(%s, %s))\n", tc_num, input1, input2);
        printf("Expected : %s\n", expected_is_same_arrangement(input1, input2) ? "true" : "false");
        printf("Actual   : %s\n", is_same_arrangement(input1, input2) ? "true" : "false");
        printf("\n");
        
        if (((is_same_arrangement(input1, input2) == true) || (is_same_arrangement(input1, input2) == false)) &&
            expected_is_same_arrangement(input1, input2) == is_same_arrangement(input1, input2)) {
        } else {
            score = 0;
        }
        printf("%s,%d,%.2f\n\n", __FILE__, tc_num, score);
    }

    if (TC4) {
        tc_num = 4;
        double score = 1;

        char* input1 = "ABCDEFGHIJKLMNOPQRST";
        char* input2 = "GHIJKLMN0PQRSTUVWXYZ";

        printf("Test %d  : expected_is_same_arrangement(%s, %s))\n", tc_num, input1, input2);
        printf("Expected : %s\n", expected_is_same_arrangement(input1, input2) ? "true" : "false");
        printf("Actual   : %s\n", is_same_arrangement(input1, input2) ? "true" : "false");
        printf("\n");
        
        if (((is_same_arrangement(input1, input2) == true) || (is_same_arrangement(input1, input2) == false)) &&
            expected_is_same_arrangement(input1, input2) == is_same_arrangement(input1, input2)) {
        } else {
            score = 0;
        }
        printf("%s,%d,%.2f\n\n", __FILE__, tc_num, score);
    }


}