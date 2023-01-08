#include <stdio.h>
#include <time.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

double bruteforce(int W, int n, double wt[n], double val[n]) {
    double smax = -1;
    // unsigned long n2 = (unsigned long) n;
    for (unsigned long i = 0; i < ((unsigned long)1 << n); i++) {
        double sum = 0;
        double size = 0;

        for (unsigned long b = 0; b < n; b++) {
            if ((i >> b) & 1) {
                sum += val[b];
                size += wt[b];
                // printf("%d\n", b);
            }
        }

        if ((sum > smax) && (size <= W)) {
            smax = sum;
            // printf("smax = %.2f\n", smax);
        }
        // printf("\n");
    }

    return smax;
}

double get_max_score(int W, int n, double wt[n], double val[n]) {
    int i, w;
    double K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - (int)wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

// Returns the maximum value that can be put in a knapsack of capacity W
double dynamic(int W, int n, double wt[n], double val[n]) {
    int i, w;
    double K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - (int)wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
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
        // {
        //     printf("―――――――――― Public Test Case ――――――――――\n");

        //     clock_t begin = clock();
        //     result = get_max_score(W, n, price, insta_score);
        //     clock_t end = clock();
        //     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        //     printf("Expected:   20.00\n");
        //     printf("Actual:     %.2f\n", result);
        //     printf("Time taken: %fs\n", time_spent);
        // }
    }

    // {
    //     clock_t begin = clock();
    //     result = dynamic(W, n, price, insta_score);
    //     clock_t end = clock();
    //     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //     printf("Dynamic   : Value = %.2f, time taken = %fs\n", result, time_spent);
    // }

    // {
    //     clock_t begin = clock();
    //     result = bruteforce(W, n, price, insta_score);
    //     clock_t end = clock();
    //     double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //     printf("Bruteforce: Value = %.2f, time taken = %fs\n", result, time_spent);
    // }
}