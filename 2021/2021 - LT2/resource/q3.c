#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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