#include <stdio.h>
#include <string.h>



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
