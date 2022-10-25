// Name :
// Email:
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void move(int n, int board[n][n], char direction[]) {

}

// DO NOT MODIFY THE CODE BELOW!

void print_board(int n, int board[n][n]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
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