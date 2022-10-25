#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void print_board(int n, int board[n][n]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void slide(int n, int arr[n][n]) {
    // for every row
    for (int i = 0; i < n; i++) {
        //for each element
        for (int j = 0; j < n - 1; j++) {
            // find a suitable element to swap or relace
            for (int k = j + 1; k < n; k++) {
                if (arr[i][k] != 0) {
                    if (arr[i][j] == 0) {
                        int temp = arr[i][j];
                        arr[i][j] = arr[i][k];
                        arr[i][k] = temp;
                        // printf("went in\n");
                    } else if (arr[i][j] == arr[i][k]) {
                        arr[i][j] += arr[i][k];
                        arr[i][k] = 0;
                        break;
                        // printf("went in 2\n");
                    } else {
                        break;
                    }
                    // break;
                }
            }
        }
    }
}

// only
void rotate(int n, int board[n][n]) {
    int result[n][n];
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            result[k][n - j - 1] = board[j][k];
        }
    }

    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            board[j][k] = result[j][k];
        }
    }
}

void move(int n, int board[n][n], char direction[]) {
    if (strcmp(direction, "left") == 0) {
        slide(4, board);
    } else if (strcmp(direction, "right") == 0) {
        rotate(4, board);
        rotate(4, board);
        slide(4, board);
        rotate(4, board);
        rotate(4, board);
    } else if (strcmp(direction, "down") == 0) {
        rotate(4, board);
        slide(4, board);
        rotate(4, board);
        rotate(4, board);
        rotate(4, board);
    } else if (strcmp(direction, "up") == 0) {
        rotate(4, board);
        rotate(4, board);
        rotate(4, board);
        // printf("--\n");
        // print_board(4, board);
        // printf("--\n");
        slide(4, board);
        rotate(4, board);
    }
}

int main(void) {
    int tc_num = 1;
    {
        // no possible move
        int board[][4] = {
            {4, 2, 6, 8},
            {4, 2, 6, 8},
            {4, 2, 4, 2},
            {4, 2, 4, 2}};
        int n = 4;
        move(n, board, "left");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:\n");
        printf("4 2 6 8\n");
        printf("4 2 6 8\n");
        printf("4 2 4 2\n");
        printf("4 2 4 2\n");
        printf("Actual:\n");
        print_board(n, board);
        printf("\n");
    }

    {
        int board[][4] = {
            {2, 0, 2, 0},
            {2, 0, 0, 0},
            {4, 2, 2, 2},
            {2, 4, 2, 2}};
        int n = 4;
        move(n, board, "right");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:\n");
        printf("0 0 0 4\n");
        printf("0 0 0 2\n");
        printf("0 4 2 4\n");
        printf("0 2 4 4\n");
        printf("Actual:\n");
        print_board(n, board);
        printf("\n");
    }

    {
        int board[][4] = {
            {2, 0, 2, 0},
            {2, 0, 0, 0},
            {4, 2, 2, 2},
            {2, 4, 2, 2}};
        int n = 4;
        move(n, board, "left");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:\n");
        printf("4 0 0 0\n");
        printf("2 0 0 0\n");
        printf("4 4 2 0\n");
        printf("2 4 4 0\n");
        printf("Actual:\n");
        print_board(n, board);
        printf("\n");
    }

        {
        int board[][4] = {
            {2, 0, 2, 0},
            {2, 0, 0, 0},
            {4, 2, 2, 2},
            {2, 4, 2, 2}};
        int n = 4;
        move(n, board, "up");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:\n");
        printf("4 2 4 4\n");
        printf("4 4 2 0\n");
        printf("2 0 0 0\n");
        printf("0 0 0 0\n");
        printf("Actual:\n");
        print_board(n, board);
        printf("\n");
    }

    
        {
        int board[][4] = {
            {2, 0, 2, 0},
            {2, 0, 0, 0},
            {4, 2, 2, 2},
            {2, 4, 2, 2}};
        int n = 4;
        move(n, board, "down");
        printf("Test Case %d\n", tc_num++);
        printf("Expected:\n");
        printf("0 0 0 0\n");
        printf("4 0 0 0\n");
        printf("4 2 2 0\n");
        printf("2 4 4 4\n");
        printf("Actual:\n");
        print_board(n, board);
        printf("\n");
    }

}