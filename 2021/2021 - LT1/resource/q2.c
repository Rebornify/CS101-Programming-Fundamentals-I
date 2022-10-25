#include <stdbool.h>
#include <stdio.h>

bool is_prime(int sum) {
    for (int i = 2; i < sum; i++) {
        if (sum % i == 0) {
            return false;
        }
    }
    return true;
}

int collect_ball(int court_a, int court_b) {
    int court_c = 1;
    int sum = court_a + court_b + court_c;

    while (!is_prime(sum)) {
        court_c++;
        sum++;
    }
    return court_c;
}

int main(void) {
    int tc_num = 1;
    {
        printf("Test %d: collect_ball(1, 1)\n", tc_num++);
        printf("Expected:1\n");
        printf("Actual  :%d\n", collect_ball(1, 1));
        printf("\n");
    }

    {
        printf("Test %d: collect_ball(3, 4)\n", tc_num++);
        printf("Expected:4\n");
        printf("Actual  :%d\n", collect_ball(3, 4));
        printf("\n");
    }

    {
        printf("Test %d:collect_ball(1, 94)\n", tc_num++);
        printf("Expected:2\n");
        printf("Actual  :%d\n", collect_ball(1, 94));
        printf("\n");
    }
} 
