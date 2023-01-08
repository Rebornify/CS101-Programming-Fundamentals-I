#include <stdio.h>

void display_ordinal_number(int num) {
    if (num < 0) {
        printf("%d", num);
        return;
    }
    
    switch (num % 100) {
        case 11:
        case 12:
        case 13:
            printf("%dth", num);
            return;
    }

    switch (num % 10) {
        case 1:
            printf("%dst", num);
            break;
        case 2:
            printf("%dnd", num);
            break;
        case 3:
            printf("%drd", num);
            break;
        default:
            printf("%dth", num);
            break;
    }
}

int main(void) {
    printf("Test 1\n");
    printf("Expected:0th\n");
    printf("Actual  :");
    display_ordinal_number(0);
    printf("\n");

    printf("Test 2\n");
    printf("Expected:1st\n");
    printf("Actual  :");
    display_ordinal_number(1);
    printf("\n");

    printf("Test 3\n");
    printf("Expected:2nd\n");
    printf("Actual  :");
    display_ordinal_number(2);
    printf("\n");

    printf("Test 4\n");
    printf("Expected:3rd\n");
    printf("Actual  :");
    display_ordinal_number(3);
    printf("\n");

    printf("Test 5\n");
    printf("Expected:4th\n");
    printf("Actual  :");
    display_ordinal_number(4);
    printf("\n");

    printf("Test 6\n");
    printf("Expected:11th\n");
    printf("Actual  :");
    display_ordinal_number(11);
    printf("\n");

    printf("Test 7\n");
    printf("Expected:12th\n");
    printf("Actual  :");
    display_ordinal_number(12);
    printf("\n");

    printf("Test 8\n");
    printf("Expected:13th\n");
    printf("Actual  :");
    display_ordinal_number(13);
    printf("\n");

    printf("Test 9\n");
    printf("Expected:21st\n");
    printf("Actual  :");
    display_ordinal_number(21);
    printf("\n");

    printf("Test 10\n");
    printf("Expected:111th\n");
    printf("Actual  :");
    display_ordinal_number(111);
    printf("\n");

    printf("Test 11\n");
    printf("Expected:121st\n");
    printf("Actual  :");
    display_ordinal_number(121);
    printf("\n");

    printf("Test 12\n");
    printf("Expected:-1\n");
    printf("Actual  :");
    display_ordinal_number(-1);
    printf("\n");


// print('Test 13')
// print('Expected:-1')
// print('Actual  :' + get_ordinal_number(-1))
// print()
    
}
