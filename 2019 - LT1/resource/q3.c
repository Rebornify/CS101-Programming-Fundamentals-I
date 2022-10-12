/*
   Name :
   Email:
 */
 
 #include <stdio.h>

int days_in_month(int month) {
    if (month == 2) {
        return 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } 
    return 31;
}

void print_season(int day, int month) {
    if (month < 1 || month > 12 || day < 1 || day > days_in_month(month)) {
        printf("invalid\n");
        return;
    }

    if (month < 3 || (month == 3 && day < 20)) {
        printf("winter");
    } else if (month < 6 || (month == 6 && day < 21)) {
        printf("spring");
    } else if (month < 9 || (month == 9 && day < 23)) {
        printf("summer");
    } else if (month < 12 || (month == 12 && day <22)) {
        printf("fall");
    } else {
        printf("winter");
    }
}

int main(void) {
    {
        printf("Test 1\n");
        printf("Expected:spring\n");
        printf("Actual  :");
        print_season(5, 5);
        printf("\n");
    }

    {
        printf("Test 2\n");
        printf("Expected:summer\n");
        printf("Actual  :");
        print_season(5, 7);
        printf("\n");
    }

    {
        printf("Test 3\n");
        printf("Expected:fall\n");
        printf("Actual  :");
        print_season(5, 11);
        printf("\n");
    }

    {
        printf("Test 4\n");
        printf("Expected:winter\n");
        printf("Actual  :");
        print_season(5, 1);
        printf("\n");
    }

    {
        printf("Test 5\n");
        printf("Expected:invalid\n");
        printf("Actual  :");
        print_season(1, 13);
        printf("\n");
    }

    {
        printf("Test 6\n");
        printf("Expected:invalid\n");
        printf("Actual  :");
        print_season(31, 4);
        printf("\n");
    }

    {
        printf("Test 7\n");
        printf("Expected:invalid\n");
        printf("Actual  :");
        print_season(-1, 4);
        printf("\n");
    }
}
