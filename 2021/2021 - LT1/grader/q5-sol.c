#include <stdbool.h>
#include <stdio.h>

// Get the next day, takes care of wraparound
int get_next_day__(int day) {
    int next_day = day + 1;

    // Wraparound
    if (next_day == 8) {
        next_day = 1;
    }

    return next_day;
}

// Get the previous day, takes care of wraparound
int get_prev_day__(int day) {
    int prev_day = day - 1;

    // Wraparound
    if (prev_day == 0) {
        prev_day = 7;
    }

    return prev_day;
}

// Computes the total full day charges between 2 days, both inclusive
double get_total_full_day_charges__(int d1, int d2) {
    int DEBUG_MODE = 0;
    if (DEBUG_MODE) printf("\nget_total_full_day_charges__(%d, %d)\n", d1, d2);

    double full_day_charge[] = { 
        0, // Why is this 0??? Think...
        30 + 24 * 0.30, // Monday full-day price = max charge per day + 24 hours * service fee = 30 + 24 * 0.30
        35 + 24 * 0.40, // Tue
        30 + 24 * 0.30, // Wed
        35 + 24 * 0.40, // Thu
        30 + 24 * 0.30, // Fri
        40 + 24 * 0.50, // Sat
        40 + 24 * 0.50  // Sun
        };

    if (d1 == d2) {
        return full_day_charge[d1];
    }

    // Count from d1 onwards
    int day = d1;
    double charges = 0;

    while (day != d2) {
        if (DEBUG_MODE) printf("    day = %d, full day charge = %.2f\n", day, full_day_charge[day]);
        charges = charges + full_day_charge[day];
        day = get_next_day__(day);
    }
    if (DEBUG_MODE) printf("    day = %d, full day charge = %.2f\n", day, full_day_charge[day]);
    charges = charges + full_day_charge[day];

    if (DEBUG_MODE) printf("    total full day charges = %.2f\n", charges);

    return charges;
}


double get_single_day_charges__(int d1, int t1, int t2) {
    int DEBUG_MODE = 0;
    if (DEBUG_MODE) printf("\nget_single_day_charges__(d1=%d, t1=%d, t2=%d)\n", d1, t1, t2);


    //                                   Mon   Tue   Wed   Thu   Fri   Sat   Sun
    double min_rental_price[]    = { 0, 12.0, 15.0, 12.0, 15.0, 12.0, 18.0, 18.0 };
    double hourly_charges[]      = { 0,  2.0,  2.5,  2.0,  2.5,  2.0,  3.0,  3.0 };
    double hourly_service_fees[] = { 0,  0.3,  0.4,  0.3,  0.4,  0.3,  0.5,  0.5 };
    double max_charge_per_day[]  = { 0, 30.0, 35.0, 30.0, 35.0, 30.0, 40.0, 40.0 };


    if (DEBUG_MODE) printf("    min_rental_price = %.2f, hourly_charges = %.2f, hourly_service_fees = %.2f\n", min_rental_price[d1], hourly_charges[d1], hourly_service_fees[d1]);


    int num_hours = (t2 - t1) / 100;
    int MIN_HOURS = 3;
    double charges = 0;

    if (DEBUG_MODE) printf("    num_hours = %d\n", num_hours);

    // add get charges excluding service fees
    if (num_hours <= MIN_HOURS) {
        charges = min_rental_price[d1];
    } else {
        charges = min_rental_price[d1] + (num_hours - MIN_HOURS) * hourly_charges[d1];
    }
    if (DEBUG_MODE) printf("    charges, before cap, excluding service fee = %.2f\n", charges);

    // cap at max charge per day
    if (charges > max_charge_per_day[d1]) {
        charges = max_charge_per_day[d1];
    }
    if (DEBUG_MODE) printf("    charges, after cap, excluding service fee = %.2f\n", charges);

    // add service fees
    double service_fees = hourly_service_fees[d1] * num_hours;
    charges = charges + service_fees;
    if (DEBUG_MODE) printf("    charges, after cap, including service fee = %.2f\n", charges);

    return charges;

}

double expected_get_rental_charges(int d1, int t1, int d2, int t2) {
    int DEBUG_MODE = 0;

    if (DEBUG_MODE) printf("\nget_rental_charges(d1=%d, t1=%d, d2=%d, t2=%d)\n", d1, t1, d2, t2);
    double charges = 0;

    if (d1 == d2) { // Case 1: 1-day rental
        if (DEBUG_MODE) printf("    Case 1: 1-day rental. Get single day charges for d1=%d\n", d1);

        // Compute charges for 1st day
        charges = get_single_day_charges__(d1, t1, t2);

    } else if (get_next_day__(d1) == d2) { // Case 2: 2-day rental
        if (DEBUG_MODE) printf("    Case 2: 2-day rental. Get (charges for d1=%d) + (charges for d2=%d)\n", d1, d2);

        // Compute charges for 1st day + 2nd day
        charges = 
            get_single_day_charges__(d1, t1, 2400) + 
            get_single_day_charges__(d2, 0, t2);

    } else { // Case 3: 3-day rental and above
        if (DEBUG_MODE) printf("    Case 3: 3-day rental and above. Get (charges for d1=%d) + (charges for d2=%d) + full day charges for all days between [%d, %d]\n", d1, d2, get_next_day__(d1), get_prev_day__(d2));

        // Compute charges for 1st day + last day + all the full days in between
        charges = 
            get_single_day_charges__(d1, t1, 2400) + 
            get_single_day_charges__(d2, 0, t2) + 
            get_total_full_day_charges__(get_next_day__(d1), get_prev_day__(d2));

    }

    return charges;
}

// // Put your code here
// double get_rental_charges(int d1, int t1, int d2, int t2) {
//     return expected_get_rental_charges(d1, t1, d2, t2);
// }


// Compares 2 doubles for equality
// From: The art of computer programming by Donald Knuth
// See also: https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
bool essentially_equal(double a, double b)
{
    double epsilon = 0.01;
    return fabs(a - b) <= ((fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

int main(void) {
    int tc_num = 1;
    if (1) {
        printf("Test %d\n", tc_num++);
        printf("get_rental_charges(1, 200, 1, 900)\n");
        printf("Expected:$22.10\n");
        printf("Actual  :$%.2f\n",
               get_rental_charges(1, 200, 1, 900));
        printf("\n");
    }

    if (1) {
        printf("Test %d\n", tc_num++);
        printf("get_rental_charges(4, 1500, 4, 1900)\n");
        printf("Expected:$19.10\n");
        printf("Actual  :$%.2f\n",
               get_rental_charges(4, 1500, 4, 1900));
        printf("\n");
    }

    if (1) {
        printf("Test %d\n", tc_num++);
        printf("get_rental_charges(7, 1300, 7, 1800)\n");
        printf("Expected:$26.50\n");
        printf("Actual  :$%.2f\n",
               get_rental_charges(7, 1300, 7, 1800));
        printf("\n");
    }

    if (1) {
        printf("Test %d\n", tc_num++);
        printf("get_rental_charges(1, 700, 2, 900)\n");
        printf("Expected:$68.70\n");
        printf("Actual  :$%.2f\n",
               get_rental_charges(1, 700, 2, 900));
        printf("\n");
    }

    if (1) {
        printf("Test %d\n", tc_num++);
        printf("get_rental_charges(4, 1200, 6, 1200)\n");
        printf("Expected:$123.00\n");
        printf("Actual  :$%.2f\n",
               get_rental_charges(4, 1200, 6, 1200));
        printf("\n");
    }

    if (1) {
        printf("Test %d\n", tc_num++);
        printf("get_rental_charges(7, 2200, 1, 300)\n");
        printf("Expected:$31.90\n");
        printf("Actual  :$%.2f\n",
               get_rental_charges(7, 2200, 1, 300));
        printf("\n");
    }

    double total_score = 0;

    if (1) {
        double this_score = 1;
        int d1 = 7;
        int t1 = 0;
        int d2 = 6;
        int t2 = 2400;

        printf("Test %d: get_rental_charges(d1=%d, t1=%d, d2=%d, t2=%d)\n", tc_num, d1, t1, d2, t2);
        printf("Expected: %.2f\n", expected_get_rental_charges(d1, t1, d2, t2));
        printf("Actual  : %.2f\n", get_rental_charges(d1, t1, d2, t2));
        printf("\n");

        if (essentially_equal(expected_get_rental_charges(d1, t1, d2, t2), get_rental_charges(d1, t1, d2, t2))) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }

    if (1) {
        double this_score = 1;
        int d1 = 5;
        int t1 = 1200;
        int d2 = 2;
        int t2 = 1200;

        printf("Test %d: get_rental_charges(d1=%d, t1=%d, d2=%d, t2=%d)\n", tc_num, d1, t1, d2, t2);
        printf("Expected: %.2f\n", expected_get_rental_charges(d1, t1, d2, t2));
        printf("Actual  : %.2f\n", get_rental_charges(d1, t1, d2, t2));
        printf("\n");

        if (essentially_equal(expected_get_rental_charges(d1, t1, d2, t2), get_rental_charges(d1, t1, d2, t2))) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }

    if (1) {
        double this_score = 1;
        int d1 = 1;
        int t1 = 1000;
        int d2 = 1;
        int t2 = 2000;

        printf("Test %d: get_rental_charges(d1=%d, t1=%d, d2=%d, t2=%d)\n", tc_num, d1, t1, d2, t2);
        printf("Expected: %.2f\n", expected_get_rental_charges(d1, t1, d2, t2));
        printf("Actual  : %.2f\n", get_rental_charges(d1, t1, d2, t2));
        printf("\n");

        if (essentially_equal(expected_get_rental_charges(d1, t1, d2, t2), get_rental_charges(d1, t1, d2, t2))) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }

    if (1) {
        double this_score = 1;
        int d1 = 4;
        int t1 = 2000;
        int d2 = 1;
        int t2 = 800;

        printf("Test %d: get_rental_charges(d1=%d, t1=%d, d2=%d, t2=%d)\n", tc_num, d1, t1, d2, t2);
        printf("Expected: %.2f\n", expected_get_rental_charges(d1, t1, d2, t2));
        printf("Actual  : %.2f\n", get_rental_charges(d1, t1, d2, t2));
        printf("\n");

        if (essentially_equal(expected_get_rental_charges(d1, t1, d2, t2), get_rental_charges(d1, t1, d2, t2))) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }

    printf("%s,%.2f\n", __FILE__, total_score);
} 
