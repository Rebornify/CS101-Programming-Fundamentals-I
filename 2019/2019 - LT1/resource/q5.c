/*
   Name :
   Email:
 */

#include <stdbool.h>
#include <stdio.h>
#include <math.h>

void print_snake(char start, char end, int len, int width) {
    int to_start = len % (width + 1);

    int needed = 0;

    if (to_start != 0) {
        needed = (width + 1) - to_start;
    }

    int num_times = ceil((double)len / (width + 1));

    int range = end - start + 1;

    if (start > end){
        range =  end - 'A' + 'Z' - start + 2;
    }

    char sequence[len + needed];

    for (int i = 0; i < needed; i++) {
        sequence[i] = ' ';
    }

    int count = 0;

    for (int i = len + needed - 1; i >= needed ; i--) {
        if (start >= 'A' && start <= 'Z') {
            sequence[i] = 'A' + ((start - 'A' + count % range) % 26);
        }
        count++;
    }

    bool is_forward = num_times % 2 == 0;

    for (int i = 0; i < len; i += width + 1) {
        if (sequence[i] != ' ') {
            if (is_forward) {
                for (int j = 0; j < width - 1; j++) {
                    printf(" ");
                }
            }
            printf("%c\n", sequence[i]);
        }

        for (int j = 0; j < width; j++) {
            if (!is_forward) {
                printf("%c", sequence[j + i + 1]);
            } else {
                printf("%c", sequence[width + i - j]);
            }
        }
        printf("\n");

        is_forward = !is_forward;
    }
}

int main(void) {
    {
        printf("=== Test 1 ===\n");
        printf("Expected:\n");
        printf("  LK\n");
        printf("   J\n");
        printf("FGHI\n");
        printf("E   \n");
        printf("DCBA\n");
        printf("\n");
        printf("Actual:\n");
        print_snake('A', 'L', 12, 4);
        printf("--------------------------------\n");
    }

    {
        printf("=== Test 2 ===\n");
        printf("Expected:\n");
        printf("C  \n");
        printf("BAC\n");
        printf("  B\n");
        printf("BCA\n");
        printf("A  \n");
        printf("CBA\n");
        printf("\n");
        printf("Actual:\n");
        print_snake('A', 'C', 12, 3);
        printf("--------------------------------\n");
    }

    {
        printf("=== Test 3 ===\n");
        printf("Expected:\n");
        printf("    B\n");
        printf("ABYZA\n");
        printf("Z\n");
        printf("YBAZY\n");
        printf("\n");
        printf("Actual:\n");
        print_snake('Y', 'B', 12, 5);
        printf("--------------------------------\n");
    }

    {
        printf("=== Test 4 ===\n");
        printf("Expected:\n");
        printf("   L\n");
        printf("   K\n");
        printf("GHIJ\n");
        printf("F\n");
        printf("EDCB\n");
        printf("\n");
        printf("Actual:\n");
        print_snake('B', 'M', 11, 4);
        printf("--------------------------------\n");
    }

    {
        printf("=== Test 5 ===\n");
        printf("Expected:\n");
        printf(" I\n");
        printf("GH\n");
        printf("F\n");
        printf("ED\n");
        printf(" C\n");
        printf("AB\n");
        printf("Z\n");
        printf("YX\n");
        printf("\n");
        printf("Actual:\n");
        print_snake('X', 'W', 12, 2);
        printf("--------------------------------\n");
    }
}