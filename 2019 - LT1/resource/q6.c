
/*
   Name :
   Email:
 */

# include <stdio.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int steal(int worth[], int nums) {
    if (nums == 0) {
        return 0;
    } 
    if (nums == 1) {
        return worth[0];
    }
    if (nums == 2) {
        return max(worth[0], worth[1]);
    }

    int dp[nums];
    dp[0] = worth[0];
    dp[1] = max(worth[0], worth[1]);
    for (int i = 2 ; i < nums; i++) { 
        dp[i] = max(worth[i] + dp[i - 2], dp[i - 1]);
    }
    return dp[nums - 1];
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
        int worth[2] = {1, 5};
        printf("Actual  :%d\n", steal(worth, 2));
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
        printf("Test 5\n");
        printf("Expected:35\n");
        int worth[5] = {1, 5, 3, 10, 30};
        printf("Actual  :%d\n", steal(worth, 5));
        printf("\n");
    }
}