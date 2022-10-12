#include <stdio.h>


int main(void) {
    {
        printf("Test 1\n");
        char *input = "aaaaaaaaaabbbaxxxxyyyzyx";
        char output[25] = {0};
        run_length_encode(input, output);
        printf("Expected:a10b3a1x4y3z1y1x1\n");
        printf("Actual  :%s\n", output);
    }

    {
        printf("Test 2\n");
        char *input = "";
        char output[25] = {0};
        run_length_encode(input, output);
        printf("Expected:><\n");
        printf("Actual  :>%s<\n", output);
    }
}