#include <stdio.h>

void identity(int n, int matrix[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
}

void print_array(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


int main(void) {
    int tc_num = 1;
    {
        int n = 3;
        int matrix[3][3];
        printf("Test Case %d\n", tc_num++);
        identity(n, matrix);
        printf("Expected:\n");
        printf("1 0 0\n");
        printf("0 1 0\n");
        printf("0 0 1\n");
        printf("Actual  :\n");
        print_array(n, n, matrix);
        printf("\n");
    }

    {
        int n = 5;
        int matrix[5][5];
        identity(n, matrix);
        printf("Test Case %d\n", tc_num++);
        printf("Expected:\n");
        printf("1 0 0 0 0\n");
        printf("0 1 0 0 0\n");
        printf("0 0 1 0 0\n");
        printf("0 0 0 1 0\n");
        printf("0 0 0 0 1\n");
        printf("Actual  :\n");
        print_array(n, n, matrix);
        printf("\n");
    }

        {
        int n = 1;
        int matrix[1][1];
        identity(n, matrix);
        printf("Test Case %d\n", tc_num++);
        printf("Expected:\n");
        printf("1\n");
        printf("Actual  :\n");
        print_array(n, n, matrix);
        printf("\n");
    }
}