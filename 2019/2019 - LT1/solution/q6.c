# include <stdio.h>
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int steal(int worth[], int num_offices) {
    if (num_offices == 0) {
        return 0;
    } 
    if (num_offices == 1) {
        return worth[0];
    }

    int previous = worth[0];
    int current = max(worth[0], worth[1]);

    for (int i = 2 ; i < num_offices; i++) { 
        int temp = max(worth[i] + previous, current);
        previous = current;
        current = temp;
        // printf("XX %d\n", current);
    }
    return current;
}

int main(void) {
    {
        printf("Test 1\n");
        printf("Expected:1\n");
        int worth[1] = {1};
        printf("Actual  :%d\n", steal(worth, 1));
        printf("\n");
    }

    {
        printf("Test 2\n");
        printf("Expected:5\n");
        int worth[3] = {1, 5, 3};
        printf("Actual  :%d\n", steal(worth, 3));
        printf("\n");
    }

    {
        printf("Test 3\n");
        printf("Expected:5\n");
        int worth[3] = {1, 5, 3};
        printf("Actual  :%d\n", steal(worth, 3));
        printf("\n");
    }

    {
        printf("Test 4\n");
        printf("Expected:15\n");
        int worth[4] = {1, 5, 3, 10};
        printf("Actual  :%d\n", steal(worth, 4));
        printf("\n");
    }

    {
        printf("Test 4\n");
        printf("Expected:25\n");
        int worth[5] = {1, 5, 3, 10, 20};
        printf("Actual  :%d\n", steal(worth, 5));
        printf("\n");
    }

    {
        printf("Test 5\n");
        printf("Expected:23\n");
        int worth[5] = {10, 9, 1, 13, 8};
        printf("Actual  :%d\n", steal(worth, 5));
        printf("\n");
    }
}
