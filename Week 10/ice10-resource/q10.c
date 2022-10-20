#include <stdio.h>
#include <string.h>

void py_slice(char orig[], char dest[], int start, int end, int step) {
    int i = 0;
    if (step >= 0) {
        for (int j = start; j < end; j += step) {
            if (orig[j] == '\0') {
                return;
            }
            dest[i++] = orig[j];
        }
    } else {
        for (int j = start; j > end; j += step) {
            while (orig[j] == '\0') {
                j--;
            }
            dest[i++] = orig[j];
        }
    }
    dest[i] = '\0';
}

int main(void) {
    {
        char orig[] = "ABCDEFGHIJ";
        char dest[11];
        py_slice(orig, dest, 1, 3, 1);
        printf("Test 1\n");
        printf("Expected:BC\n");
        printf("Actual  :%s\n", dest);
        printf("\n");
    }

    {
        char orig[] = "ABCDEFGHIJ";
        char dest[11];
        py_slice(orig, dest, 0, 9, 1);
        printf("Test 2\n");
        printf("Expected:ABCDEFGHI\n");
        printf("Actual  :%s\n", dest);
        printf("\n");
    }

    {
        char orig[] = "ABCDEFGHIJ";
        char dest[11];
        py_slice(orig, dest, 0, 11, 1);
        printf("Test 3\n");
        printf("Expected:ABCDEFGHIJ\n");
        printf("Actual  :%s\n", dest);
        printf("\n");
    }

    {
        char orig[] = "ABCDEFGHIJ";
        char dest[11];
        py_slice(orig, dest, 0, 10, 2);
        printf("Test 4\n");
        printf("Expected:ACEGI\n");
        printf("Actual  :%s\n", dest);
        printf("\n");
    }

    {
        char orig[] = "ABCDEFGHIJ";
        char dest[11];
        py_slice(orig, dest, 0, 10, -2);
        printf("Test 5\n");
        printf("Expected:><\n");
        printf("Actual  :>%s<\n", dest);
        printf("\n");
    }

    {
        char orig[] = "ABCDEFGHIJ";
        char dest[11];
        py_slice(orig, dest, 10, 2, -2);
        printf("Test 6\n");
        printf("Expected:JHFD\n");
        printf("Actual  :%s\n", dest);
        printf("\n");
    }

    {
        char orig[] = "ABCDEFGHIJ";
        char dest[11];
        py_slice(orig, dest, 10, 2, 0);
        printf("Test 6\n");
        printf("Expected:><\n");
        printf("Actual  :>%s<\n", dest);
        printf("\n");
    }
    
    {
        char orig[] = "ABCDEFGHIJ";
        char dest[11];
        py_slice(orig, dest, 7, 2, -3);
        printf("Test 6\n");
        printf("Expected:HE\n");
        printf("Actual  :%s\n", dest);
        printf("\n");
    }
}
