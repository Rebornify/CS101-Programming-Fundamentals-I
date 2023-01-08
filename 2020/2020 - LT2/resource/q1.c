// Name :
// Email:

#include <string.h>
#include <stdio.h>
#include <math.h>

int percent(char votes[], char candidate) {
    int total_votes = strlen(votes);
    if (total_votes == 0) {
        return 0;
    }

    int vote_count = 0;
    for (int i = 0; i < total_votes; i++) {
        if (votes[i] == candidate) {
            vote_count++;
            printf("%d", vote_count);
        }
    }
    
    return (vote_count * 100 / total_votes);
}

// DO NOT MODIFY THE CODE BELOW!
int main(void) {
    int tc_num = 1;
    {
        char *votes = "BBBTTBBBTT";
        int result = percent(votes, 'T');
        printf("Test Case %d\n", tc_num++);
        printf("Expected:40\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }   

    {
        char *votes = "BBBTTBBBTT";
        int result = percent(votes, 'B');
        printf("Test Case %d\n", tc_num++);
        printf("Expected:60\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    } 

    {
        char *votes = "BBBT";
        int result = percent(votes, 'B');
        printf("Test Case %d\n", tc_num++);
        printf("Expected:75\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        char *votes = "";
        int result = percent(votes, 'A');
        printf("Test Case %d\n", tc_num++);
        printf("Expected:0\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        char *votes = "CDDDDDD";
        int result = percent(votes, 'C');
        printf("Test Case %d\n", tc_num++);
        printf("Expected:14\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        char *votes = "CBD";
        int result = percent(votes, 'A');
        printf("Test Case %d\n", tc_num++);
        printf("Expected:0\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        char *votes = "A";
        int result = percent(votes, 'A');
        printf("Test Case %d\n", tc_num++);
        printf("Expected:100\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

}