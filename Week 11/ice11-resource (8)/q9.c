#include <stdbool.h>
#include <stdio.h>

bool valid_nums(int n, int values[][n]) {
    bool temp[9] = {false};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int current = values[i][j];
            if (current < 1 || current > 9) {
                return false;
            }
            temp[current - 1]++;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (temp[i] != true) {
            return false;
        }
    }

    return true;
}

bool valid_sums(int n, int values[][n]) {
    for (int i = 0; i < n; i++) {
        int sum_row = 0;
        int sum_col = 0;

        for (int j = 0; j < n; j++) {
            sum_row += values[i][j];
            sum_col += values[j][i];
        }

        if (sum_row != 15 || sum_col != 15) {
            return false;
        }
    }

    int sum_diag1 = values[0][0] + values[1][1] + values[2][2];
    int sum_diag2 = values[2][0] + values[1][1] + values[0][2];

    if (sum_diag1 != 15 || sum_diag2 != 15) {
        return false;
    }

    return true;
}

bool is_magic_square(int n, int values[][n]) {
    if (!valid_nums(n, values)) {
        return false;
    }

    if (!valid_sums(n, values)) {
        return false;
    }

    return true;
}

int main(void) {
    {
        int values[][3] = {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}};
        printf("Test 1:%s\n", is_magic_square(3, values) ? "Pass" : "Fail");
        printf("\n");
    }
    {
        int values[][3] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
        printf("Test 2:%s\n", is_magic_square(3, values) ? "Pass" : "Fail");
        printf("\n");
    }
    {
        int values[][3] = {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}};
        printf("Test 3:%s\n", is_magic_square(3, values) ? "Pass" : "Fail");
        printf("\n");
    }
    {
        int values[][3] = {{5, 5, 5}, {5, 5, 5}, {5, 5, 5}};
        printf("Test 4:%s\n", is_magic_square(3, values) ? "Fail" : "Pass");
        printf("\n");
    }
    {
        int values[][3] = {{2, 6, 7}, {9, 5, 1}, {4, 3, 8}};
        printf("Test 5:%s\n", is_magic_square(3, values) ? "Fail" : "Pass");
        printf("\n");
    }
    {
        int values[][3] = {{10, 4, 1}, {1, 5, 9}, {4, 6, 5}};
        printf("Test 6:%s\n", is_magic_square(3, values) ? "Fail" : "Pass");
        printf("\n");
    }
}
