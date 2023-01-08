#include <stdio.h>

void run_length_encode(char *input, char *output) {
    while (*input != '\0') {
        *output++ = *input;

        int r_len = 1;
        while (*input == *(input + 1)) {
            r_len++;
            
            input++;
        }
        
        output += sprintf(output, "%d", r_len);

        input++;
    }
    *output = '\0';
}

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