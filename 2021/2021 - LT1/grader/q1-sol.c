#include <math.h>


int expected_convert(double temp, char scale) {

    if (scale == 'C') {
        return 9.0/5.0 * temp + 32;
    } else if (scale == 'F') {
        return 5.0/9.0 * (temp - 32);
    }

    return 0; 
}

// Put your code here
// int convert(double temp, char scale) {
//     return expected_convert(temp, scale);
// }


int main(void) {
    int tc_num = 1;
    if (0) {
        // TC 1
        int temp = 30;
        char scale = 'C';
        printf("Test %d: convert(%d, %c)\n", tc_num++, temp, scale);
        printf("Expected:86\n");
        printf("Actual  :%d\n", convert(temp, scale));
        printf("\n");
    }

    if (0) {
        // TC 2
        int temp = 50;
        char scale = 'F';
        printf("Test %d: convert(%d, %c)\n", tc_num++, temp, scale);
        printf("Expected:10\n");
        printf("Actual  :%d\n", convert(temp, scale));
        printf("\n");
    }

    if (0) {
        // TC 3
        int temp = -55;
        char scale = 'C';
        printf("Test %d: convert(%d, %c)\n", tc_num++, temp, scale);
        printf("Expected:-67\n");
        printf("Actual  :%d\n", convert(temp, scale));
        printf("\n");
    }

    double total_score = 0;

    if (1) {
        double this_score = 1.5;
        int temp = 0;
        char scale = 'C';

        printf("Test %d: convert(%d, %c)\n", tc_num, temp, scale);
        printf("Expected:%d\n", expected_convert(temp, scale));
        printf("Actual  :%d\n", convert(temp, scale));
        printf("\n");

        if (expected_convert(temp, scale) == convert(temp, scale)) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }

    if (1) {
        double this_score = 1.5;
        double temp = 0;
        char scale = 'F';

        printf("Test %d: convert(%.2f, %c)\n", tc_num, temp, scale);
        printf("Expected:%d\n", expected_convert(temp, scale));
        printf("Actual  :%d\n", convert(temp, scale));
        printf("\n");

        if (expected_convert(temp, scale) == convert(temp, scale)) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }

    if (1) {
        double this_score = 1.5;
        double temp = -273;
        char scale = 'C';

        printf("Test %d: convert(%.2f, %c)\n", tc_num, temp, scale);
        printf("Expected:%d\n", expected_convert(temp, scale));
        printf("Actual  :%d\n", convert(temp, scale));
        printf("\n");

        if (expected_convert(temp, scale) == convert(temp, scale)) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }

    if (1) {
        double this_score = 1.5;
        double temp = -460;
        char scale = 'F';

        printf("Test %d: convert(%.2f, %c)\n", tc_num, temp, scale);
        printf("Expected:%d\n", expected_convert(temp, scale));
        printf("Actual  :%d\n", convert(temp, scale));
        printf("\n");

        if (expected_convert(temp, scale) == convert(temp, scale)) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }

    if (1) {
        double this_score = 1;
        double temp = 8.8;
        char scale = 'C';

        printf("Test %d: convert(%.2f, %c)\n", tc_num, temp, scale);
        printf("Expected:%d\n", expected_convert(temp, scale));
        printf("Actual  :%d\n", convert(temp, scale));
        printf("\n");

        if (expected_convert(temp, scale) == convert(temp, scale)) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }

    if (1) {
        double this_score = 1;
        double temp = 8.8;
        char scale = 'F';

        printf("Test %d: convert(%.2f, %c)\n", tc_num, temp, scale);
        printf("Expected:%d\n", expected_convert(temp, scale));
        printf("Actual  :%d\n", convert(temp, scale));
        printf("\n");

        if (expected_convert(temp, scale) == convert(temp, scale)) {
            total_score = total_score + this_score;
        }

        tc_num++;
    }
        
    printf("%s,%.2f\n\n", __FILE__, total_score);
}