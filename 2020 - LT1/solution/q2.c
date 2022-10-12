/*
    Name:
    Email:

*/
#include <stdio.h>

// write your answer below
void move_robot(int position[], char moves[], int n) {
    for (int i = 0; i < n; i++) {
        int num_times = 1;
        if (moves[i] >= '0' && moves[i] <= '9') {
            num_times = moves[i] - '0';
            i++;
        }

        for (int j = 0; j < num_times; j++) {
            if (moves[i] == 'N') {
                position[1] += 1;
            } else if (moves[i] == 'S') {
                position[1] -= 1;
            } else if (moves[i] == 'E') {
                position[0] += 1;
            } else if (moves[i] == 'W') {
                position[0] -= 1;
            }
        }
    }
}

// do not edit the main method.

int main(void) {
    int tc_num = 1;
    {
        printf("Test %d\n", tc_num++);
        char moves[] = {'N', 'N', 'N', 'S', 'S'};
        int position[] = {0, 0};
        move_robot(position, moves, sizeof(moves) / sizeof(char));
        printf("Expected:(0,1)\n");
        printf("Actual  :(%d,%d)\n", position[0], position[1]);
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        char moves[] = {'N', 'E', 'W', 'S', 'N', 'E', 'W', 'S'};
        int position[] = {1, 1};
        move_robot(position, moves, sizeof(moves) / sizeof(char));
        printf("Expected:(1,1)\n");
        printf("Actual  :(%d,%d)\n", position[0], position[1]);
        printf("\n");
    }

    {
        printf("Test %d\n", tc_num++);
        char moves[] = {'5', 'N', 'E', 'E'};
        int position[] = {3, 1};
        move_robot(position, moves, sizeof(moves) / sizeof(char));
        printf("Expected:(5,6)\n");
        printf("Actual  :(%d,%d)\n", position[0], position[1]);
        printf("\n");
    }

    {
        char moves[] = {'N', 'N', 'N', 'S', 'S'};
        int position[] = {0, 0};
        move_robot(position, moves, sizeof(moves) / sizeof(char));
        printf("Test %d\n", tc_num++);
        printf("Expected:(0,1)\n");
        printf("Actual  :(%d,%d)\n", position[0], position[1]);
        printf("\n");
    }

    {
        char moves[] = {'3', 'N', 'S', 'E', 'E', '2', 'E'};
        int position[] = {1, 5};
        move_robot(position, moves, sizeof(moves) / sizeof(char));
        printf("Test %d\n", tc_num++);
        printf("Expected:(5,7)\n");
        printf("Actual  :(%d,%d)\n", position[0], position[1]);
        printf("\n");
    }
}