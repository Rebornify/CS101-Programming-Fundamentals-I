#include <stdbool.h>
#include <stdio.h>

bool is_prime(int num) {
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int collect_ball(int court_a, int court_b) {
    int total_so_far = court_a + court_b;

    int court_c = 1;
    while (!is_prime(total_so_far + court_c)) {
        court_c++;
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
