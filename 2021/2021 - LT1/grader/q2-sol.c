#include <stdbool.h>
#include <stdio.h>
#include <math.h>

// Returns true if n is prime, false otherwise
bool is_prime__(n) {
    for (int i = 2; i <= sqrt(n); i++) {

        // if n is divisible by any number, it isn't prime
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}


int expected_collect_ball(int court1, int court2) {
    int num_balls = 1;

    // Keep increasing num_balls until the sum of all 3 courts is a prime number
    while (!is_prime__(num_balls + court1 + court2)) {
        num_balls++;
    }

    return num_balls;
}


// Put your code here
// int collect_ball(int court1, int court2) {
//     return expected_collect_ball(court1, court2);
// }


int main(void) {
    int tc_num = 1;
    if (0) {
        printf("Test %d: collect_ball(1, 1)\n", tc_num++);
        printf("Expected:1\n");
        printf("Actual  :%d\n", collect_ball(1, 1));
        printf("\n");
    }

    if (0) {
        printf("Test %d: collect_ball(3, 4)\n", tc_num++);
        printf("Expected:4\n");
        printf("Actual  :%d\n", collect_ball(3, 4));
        printf("\n");
    }

    if (0) {
        printf("Test %d:collect_ball(1, 94)\n", tc_num++);
        printf("Expected:2\n");
        printf("Actual  :%d\n", collect_ball(1, 94));
        printf("\n");
    }


    double total_score = 0;

    {
        double this_score = 1;
        int court1 = 1;
        int court2 = 1;

        printf("Test %d: collect_ball(%d, %d)\n", tc_num, court1, court2);
        printf("Expected:%d\n", expected_collect_ball(court1, court2));
        printf("Actual  :%d\n", collect_ball(court1, court2));
        printf("\n");

        if (expected_collect_ball(court1, court2) == collect_ball(court1, court2)) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }

    {
        double this_score = 2;
        int court1 = 1234;
        int court2 = 5678;

        printf("Test %d: collect_ball(%d, %d)\n", tc_num, court1, court2);
        printf("Expected:%d\n", expected_collect_ball(court1, court2));
        printf("Actual  :%d\n", collect_ball(court1, court2));
        printf("\n");

        if (expected_collect_ball(court1, court2) == collect_ball(court1, court2)) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }

    {
        double this_score = 2;
        int court1 = 77;
        int court2 = 77;

        printf("Test %d: collect_ball(%d, %d)\n", tc_num, court1, court2);
        printf("Expected:%d\n", expected_collect_ball(court1, court2));
        printf("Actual  :%d\n", collect_ball(court1, court2));
        printf("\n");

        if (expected_collect_ball(court1, court2) == collect_ball(court1, court2)) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }
        
    printf("%s,%.2f\n", __FILE__, total_score);
}
