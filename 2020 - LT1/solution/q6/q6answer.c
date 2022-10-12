/*
    Name:
    Email:

*/
// write your answer below
#include <stdio.h>

// not the fastest sort but the only sort we have learnt so far ...
void bubble_sort(int values[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (values[j] > values[j + 1]) {
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
}

int get_crowd_size(int timings[], int n) {
    int half_n = n / 2;
    int entries[half_n];
    int exits[half_n];

    for (int i = 0; i < n; i += 2) {
        entries[i / 2] = timings[i];
        exits[i / 2] = timings[i + 1];
    }

    bubble_sort(entries, half_n);
    bubble_sort(exits, half_n);

    int highest = 0;
    int count = 0;
    int entries_pos = 0;
    int exits_pos = 0;
    while (entries_pos < half_n && exits_pos < half_n) {
        if (entries[entries_pos] < exits[exits_pos]) {
            count += 1;
            entries_pos++;
        } else {
            count -= 1;
            exits_pos++;
        }

        if (count > highest) {
            highest = count;
        }
    }

    return highest;
}
