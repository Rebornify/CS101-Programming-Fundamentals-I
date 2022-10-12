#include <stdio.h>
#include <math.h>
#include <string.h>


/**
 * Shifts an array index to the left or right, and takes care of index wraparound.
 *
 * @param len        Length of the array
 * @param index      The index to shift
 * @param direction  The direction to shift. -1 = left, 1 = right
 *
 */
int shift_index__(int len, int index, int direction) {
    // the new index is just the current index -1 or +1
    int new_index = index + direction;

    if (new_index == len) {
        // If new index is too far right, then wraparound to 0
        new_index = 0;
    } else if (new_index == -1) {
        // If new index is too far left, then wraparound to len - 1
        new_index = len - 1;
    }

    return new_index;
}


/**
 * Computes the sum of neighbors in a specific direction.
 *
 * @param arr          The array
 * @param len          Length of the array
 * @param m            Number of neighbors to include, in one direction only
 * @param start_index  The index to start from. arr[start_index] is NOT included in the sum
 * @param direction    The direction to sum. -1 = left, 1 = right, 0 = gg
 *
 * @return The sum of neighbors in the specified direction.
 *
 * See also: https://www.youtube.com/watch?v=Y1xs_xPb46M
 */
double get_sum_of_neighbors_in_one_direction__(int arr[], int len, int m, int start_index, int direction) {
    // printf("\nget_sum_of_neighbors_in_one_direction__(m=%d, start_index=%d, direction=%d)\n", m, start_index, direction);
    double sum = 0;

    int j = start_index;
    
    j = shift_index__(len, j, direction);
    for (int i = 0; i < m; i++) {

        sum = sum + arr[j];
        // printf("    j = %d, arr[j] = %d, sum = %d\n", j, arr[j], sum);
        j = shift_index__(len, j, direction);
    }

    // printf("    sum = %d\n", sum);
    return sum;
}


/**
 * Computes the mean of neighbors in both directions
 *
 * @param arr          The array
 * @param len          Length of the array
 * @param n            Number of neighbors to include, on each side. The total number of neighbors is 2*n
 * @param start_index  The index to start from. arr[start_index] is NOT included in the mean
 *
 * @return The sum of neighbors in the specified direction.
 *
 */
double get_mean_of_neighbors__(int arr[], int len, int n, int start_index) {
    int LEFT_DIRECTION = -1;
    // int GG_DIRECTION = 0;
    int RIGHT_DIRECTION = 1;

    double DIVISOR = 2.0 * n; // n neighbors on each side, so total number of neighbors = 2*n
    return 
        (get_sum_of_neighbors_in_one_direction__(arr, len, n, start_index, LEFT_DIRECTION) + 
         get_sum_of_neighbors_in_one_direction__(arr, len, n, start_index, RIGHT_DIRECTION)) / DIVISOR;
}


// Sets all the elements of an array to 0
void init_array__(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = 0;
    }
}


// Copies all elements in the "from" array to the "to" array. Both arrays must be the same length
void copy_array__(int from[], int to[], int len) {
    for (int i = 0; i < len; i++) {
        to[i] = from[i];
    }
}


// Prints an array
void print_array__(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void expected_support(int numbers[], int len, int n) {
    // printf("\nsupport(len=%d, n=%d):\n", len, n);

    // Create a new array to store the results, temporarily
    int supported[len];
    init_array__(supported, len);
    // print_array__(numbers, len);

    for (int i = 0; i < len; i++) {
        double mean = get_mean_of_neighbors__(numbers, len, n, i);
        // printf("    i = %d, numbers[i] = %d, mean = %.2f\n", i, numbers[i], mean);
        if (numbers[i] < mean) {
            supported[i] = 1.5 * numbers[i];
        } else {
            supported[i] = numbers[i];
        }
    }

    // copy supported back to numbers
    copy_array__(supported, numbers, len);
}


// // Put your code here
// void support(int numbers[], int len, int n) {
//     expected_support(numbers, len, n);
// }


int main(void) {
    int tc_num = 1;
 
    if (0) {
        int arr[] = {2, 4, 3};
        printf("Test %d\n", tc_num++);
        printf("Expected:3 4 3\n");
        printf("Actual  :");
        support(arr, sizeof(arr)/sizeof(arr[0]), 1);
        print_array__(arr, sizeof(arr)/sizeof(arr[0]));
        printf("\n");
    }
    
    if (0) {
        int arr[] = {5, 7, 11, 12, 1, 17, 23};
        printf("Test %d\n", tc_num++);
        printf("Expected:7 10 11 12 1 17 23\n");
        printf("Actual  :");
        support(arr, sizeof(arr)/sizeof(arr[0]), 1);
        print_array__(arr, sizeof(arr)/sizeof(arr[0]));
        printf("\n");
    }

    if (0) {
        int arr[] = {9, 10, 4, 32, 16, 18, 10};
        printf("Test %d\n", tc_num++);
        printf("Expected:13 15 6 32 16 18 15\n");
        printf("Actual  :");
        support(arr, sizeof(arr)/sizeof(arr[0]), 2);
        print_array__(arr, sizeof(arr)/sizeof(arr[0]));
        printf("\n");
    }

    if (0) {
        int arr[] = {9, 10, 4, 32, 16, 18};
        printf("Test %d\n", tc_num++);
        printf("Expected:13 15 6 32 16 18\n");
        printf("Actual  :");
        support(arr, sizeof(arr)/sizeof(arr[0]), 3);
        print_array__(arr, sizeof(arr)/sizeof(arr[0]));
        printf("\n");
    }

    double total_score = 0;

    if (1) {
        double this_score = 1;
        int arr[] = {10, 100, 10, 100, 10, 100, 10};
        int len = sizeof(arr) / sizeof(arr[0]);
        int expected_arr[len];
        int n = 3;
        memcpy(expected_arr, arr, len*sizeof(expected_arr[0]));

        expected_support(expected_arr, len, n);
        support(arr, len, n);

        printf("Test %d: support(len=%d, n=%d)\n", tc_num, len, n);
        printf("Expected: ");
        print_array__(expected_arr, len);
        printf("Actual  : ");
        print_array__(arr, len);
        printf("\n");

        if (memcmp(arr, expected_arr, len*sizeof(arr[0])) == 0) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }

    if (1) {
        double this_score = 1;
        int arr[] = {9, 1, 5, 2, 3, 3, 7, 8, 20, 40};
        int len = sizeof(arr) / sizeof(arr[0]);
        int expected_arr[len];
        int n = 5;
        memcpy(expected_arr, arr, len*sizeof(expected_arr[0]));

        expected_support(expected_arr, len, n);
        support(arr, len, n);

        printf("Test %d: support(len=%d, n=%d)\n", tc_num, len, n);
        printf("Expected: ");
        print_array__(expected_arr, len);
        printf("Actual  : ");
        print_array__(arr, len);
        printf("\n");

        if (memcmp(arr, expected_arr, len*sizeof(arr[0])) == 0) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }

    if (1) {
        double this_score = 1;
        int arr[] = {2, 8, 10, 9, 45, 3, 5, 22, 33};
        int len = sizeof(arr) / sizeof(arr[0]);
        int expected_arr[len];
        int n = 4;
        memcpy(expected_arr, arr, len*sizeof(expected_arr[0]));

        expected_support(expected_arr, len, n);
        support(arr, len, n);

        printf("Test %d: support(len=%d, n=%d)\n", tc_num, len, n);
        printf("Expected: ");
        print_array__(expected_arr, len);
        printf("Actual  : ");
        print_array__(arr, len);
        printf("\n");

        if (memcmp(arr, expected_arr, len*sizeof(arr[0])) == 0) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }

    if (1) {
        double this_score = 1;
        int arr[] = {1, 20, 3, 4, 5, 4, 3, 20, 1};
        int len = sizeof(arr) / sizeof(arr[0]);
        int expected_arr[len];
        int n = 1;
        memcpy(expected_arr, arr, len*sizeof(expected_arr[0]));

        expected_support(expected_arr, len, n);
        support(arr, len, n);

        printf("Test %d: support(len=%d, n=%d)\n", tc_num, len, n);
        printf("Expected: ");
        print_array__(expected_arr, len);
        printf("Actual  : ");
        print_array__(arr, len);
        printf("\n");

        if (memcmp(arr, expected_arr, len*sizeof(arr[0])) == 0) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }

    printf("%s,%.2f\n", __FILE__, total_score);
}