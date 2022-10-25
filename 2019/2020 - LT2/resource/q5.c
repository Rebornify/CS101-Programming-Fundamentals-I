#include <stdio.h>
#include <time.h>


double get_max_score(int budget, int n, double prices[n], double insta_scores[n]) {
    return 0;
}


int main() {
    int test_id = 0;

    {
        double insta_score[4] = {2, 6, 3, 1};
        double price[4] = {1, 2, 4, 5};
        int n = 4;
        int budget = 20;
        clock_t begin = clock();

        double result = get_max_score(budget, n, price, insta_score);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Expected:   12.00\n");
        printf("Actual:     %.2f\n", result);
        printf("Time taken: %fs\n", time_spent);
        printf("\n");
    }

    {
        double insta_score[10] = {2, 6, 3, 1, 2, 3, 4, 5, 6, 17};
        double price[10] = {1, 2, 4, 5, 6, 4, 4, 3, 9, 10};
        int n = 10;
        int budget = 20;
        clock_t begin = clock();

        double result = get_max_score(budget, n, price, insta_score);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Expected:   34.00\n");
        printf("Actual:     %.2f\n", result);
        printf("Time taken: %fs\n", time_spent);
        printf("\n");
    }
    {
        double insta_score[100] = {0};
        double price[100] = {0};
        int n = 100;
        for (int i = 0; i < n; i++) {
            insta_score[i] = i;
            price[i] = i;
        }
        double result = 0;
        int budget = 20;

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);

        clock_t begin = clock();
        result = get_max_score(budget, n, price, insta_score);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        printf("Expected:   20.00\n");
        printf("Actual:     %.2f\n", result);
        printf("Time taken: %fs\n", time_spent);
        printf("\n");
    }
}