#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Returns the number of digits in n
int get_num_digits__(int n) {
    int num_digits = 0;

    n = abs(n);
    while (n > 0) { 
        n = n / 10;
        num_digits++;
    }

    return num_digits;
}

// Returns 0 if n has an even number of digits, or 1 otherwise
int num_middle_digits__(int n) {
    if (get_num_digits__(n) % 2 == 0) {
        return 0;
    } else {
        return 1;
    }
}

// Returns the middle digit of a number with odd number of digits; returns 0 otherwise
int get_middle_digit__(int n) {
    int middle_digit = abs(n);

    // Return 0 if there are no middle digits, i.e. this number has an even number of digits
    if (num_middle_digits__(n) == 0) {
        return 0;
    }

    // Get the middle digit
    for (int i = 0; i < get_num_digits__(n) / 2; i++) {
        middle_digit = middle_digit / 10;
    }
    middle_digit = middle_digit % 10;
    
    return middle_digit;
}

// Returns true if a number is negative, false otherwise
bool is_negative__(long n) {
    return (n < 0);
}

// Returns a number, reversed
long reverse_number__(long n) {
    long reversed_n = 0;
    while (n > 0) {    
     int remainder = n % 10;    
     reversed_n = reversed_n * 10 + remainder;    
     n = n / 10;    
  }

  return reversed_n;
}

// Zeros on right side must be handled carefully, e.g. LLLM001 must be reversed to LLLM100
long reverse_number_right_side(long right_side, int right_side_factor) {
    // printf("\nreverse_number_right_side(right_side=%ld, right_side_factor=%d)\n", right_side, right_side_factor);

    // adjust the right side factor to "line it up" with the right side number
    int right_side_factor_adjusted = right_side_factor / 10;
    // printf("    right_side_factor_adjusted = %d\n", right_side_factor_adjusted);

    if (right_side >= right_side_factor_adjusted) {
        // Right side starts with a non-zero number (e.g. LLLM1??, LLLM2??, LLLM3??), just use reverse_number__()
        return reverse_number__(right_side);
    }

    // Right side starts with a 0, make the zero a one temporarily. e.g. LLLM0?? ➜ LLLM1??
    right_side = right_side + right_side_factor_adjusted;

    // Reverse it, then minus the one
    right_side = reverse_number__(right_side);
    right_side = right_side - 1;

    return right_side;
}


long expected_flip_number(int num) {
    long flipped_num = 0;
    int abs_num = abs(num);
    int middle_digit = get_middle_digit__(num);
    int DEBUG_MODE = 0; // who dis?

    if (DEBUG_MODE) {
        printf("\nflip_number(num=%d)\n", num);
        printf("    abs(num) = %d\n", abs_num);
        printf("    num digits = %d\n", get_num_digits__(num));
        printf("    is negative = %d\n", is_negative__(num));
        printf("    num middle digits = %d\n", num_middle_digits__(num));
        printf("    middle digit = %d\n", get_middle_digit__(num));
    }

    // These 2 values are 10, 100, 1000, 10000, etc. 
    // Think of them like a "knife", they can cut the left and right sides out
    long left_side_factor = pow(10, (get_num_digits__(num) / 2) + num_middle_digits__(num)); // Why + num_middle_digits 🤔??? I wonder ... 🤯
    long right_side_factor = pow(10, get_num_digits__(num) / 2);

    long left_side = abs_num / left_side_factor; // cut the right side, leave the left side
    long right_side = abs_num % right_side_factor; // cut the left side, leave the right side

    if (DEBUG_MODE) {
        printf("    left_side_factor = %ld\n", left_side_factor);
        printf("    right_side_factor = %ld\n", right_side_factor);
        printf("    left_side = %ld\n", left_side);
        printf("    right_side = %ld\n", right_side);
    }

    long left_side_reversed = reverse_number__(left_side);
    long right_side_reversed = reverse_number_right_side(right_side, right_side_factor);

    if (DEBUG_MODE) {
        printf("    left_side_reversed = %ld\n", left_side_reversed);
        printf("    right_side_reversed = %ld\n", right_side_reversed);
    }

    // Combine the left, middle, right
    flipped_num = 
        right_side_reversed + 
        middle_digit * right_side_factor + 
        left_side_reversed * left_side_factor;

    // Put the -ve sign back
    if (is_negative__(num)) {
        flipped_num = -flipped_num;
    }

    return flipped_num;
}


// // Put your code here
// long flip_number(int num) {
//     return expected_flip_number(num);
// }


int main(void) {
    int tc_num = 1;
    if (0) {
        printf("Test %d\n", tc_num++);
        printf("Expected:7\n");
        printf("Actual  :%ld\n", flip_number(7));
        printf("\n");
    }

    if (0) {
        printf("Test %d\n", tc_num++);
        printf("Expected:68\n");
        printf("Actual  :%ld\n", flip_number(68));
        printf("\n");
    }

    if (0) {
        printf("Test %d\n", tc_num++);
        printf("Expected:87245\n");
        printf("Actual  :%ld\n", flip_number(78254));
        printf("\n");
    }

    if (0) {
        printf("Test %d\n", tc_num++);
        printf("Expected:2758543\n");
        printf("Actual  :%ld\n", flip_number(5728345));
        printf("\n");
    }

    if (0) {
        printf("Test %d\n", tc_num++);
        printf("Expected:-2\n");
        printf("Actual  :%ld\n", flip_number(-2));
        printf("\n");
    }

    if (0) {
        printf("Test %d\n", tc_num++);
        printf("Expected:-23\n");
        printf("Actual  :%ld\n", flip_number(-23));
        printf("\n");
    }

    if (0) {
        printf("Test %d\n", tc_num++);
        printf("Expected:-213\n");
        printf("Actual  :%ld\n", flip_number(-213));
        printf("\n");
    }

    if (0) {
        printf("Test %d\n", tc_num++);
        printf("Expected:-3254\n");
        printf("Actual  :%ld\n", flip_number(-2345));
        printf("\n");
    }
    
    if (0) {
        printf("Test %d\n", tc_num++);
        printf("Expected:-254\n");
        printf("Actual  :%ld\n", flip_number(-2045));
        printf("\n");
    }
  
    if (0) {
        printf("Test %d\n", tc_num++);
        printf("Expected:1054\n");
        // 100 -> 001, 450 -> 054
        // thus 001054
        printf("Actual  :%ld\n", flip_number(100450));
        printf("\n");
    }

    double total_score = 0;

    if (1) {
        double this_score = 1;
        int num = 1234321;

        printf("Test %d: flip_number(%d)\n", tc_num, num);
        printf("Expected:%ld\n", expected_flip_number(num));
        printf("Actual  :%ld\n", flip_number(num));
        printf("\n");

        if (expected_flip_number(num) == flip_number(num)) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }

    if (1) {
        double this_score = 1;
        int num = 2147483647;

        printf("Test %d: flip_number(%d)\n", tc_num, num);
        printf("Expected:%ld\n", expected_flip_number(num));
        printf("Actual  :%ld\n", flip_number(num));
        printf("\n");

        if (expected_flip_number(num) == flip_number(num)) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }

    if (1) {
        double this_score = 1;
        int num = 10203;

        printf("Test %d: flip_number(%d)\n", tc_num, num);
        printf("Expected:%ld\n", expected_flip_number(num));
        printf("Actual  :%ld\n", flip_number(num));
        printf("\n");

        if (expected_flip_number(num) == flip_number(num)) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }

    if (1) {
        double this_score = 1;
        int num = 10000;

        printf("Test %d: flip_number(%d)\n", tc_num, num);
        printf("Expected:%ld\n", expected_flip_number(num));
        printf("Actual  :%ld\n", flip_number(num));
        printf("\n");

        if (expected_flip_number(num) == flip_number(num)) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }

    printf("%s,%.2f\n", __FILE__, total_score);
}
