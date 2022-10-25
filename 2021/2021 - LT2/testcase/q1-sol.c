#include <stdio.h>
#include <string.h>

#define TC1 1
#define TC2 1
#define TC3 1
#define TC4 1
#define TC5 1

#if SINGLE_TC == 1
#define TC1 1
#define TC2 0
#define TC3 0
#define TC4 0
#define TC5 0
#endif

#if SINGLE_TC == 2
#define TC1 0
#define TC2 1
#define TC3 0
#define TC4 0
#define TC5 0
#endif

#if SINGLE_TC == 3
#define TC1 0
#define TC2 0
#define TC3 1
#define TC4 0
#define TC5 0
#endif

#if SINGLE_TC == 4
#define TC1 0
#define TC2 0
#define TC3 0
#define TC4 1
#define TC5 0
#endif

#if SINGLE_TC == 5
#define TC1 0
#define TC2 0
#define TC3 0
#define TC4 0
#define TC5 1
#endif

int expected_get_score(char responses[], char answers[]) {
    int num_correct = 0;
    int num_questions = strlen(responses);

    for (int i = 0; i < num_questions; i++) {
        if (responses[i] == answers[i]) {
            num_correct++;
        }
    }

    return 100 * num_correct / num_questions;
}

int main(void) {
    int tc_num = 1;
    if (0) {
        char *responses = "AB";
        char *answers = "CD";    
        printf("Test %d  :get_score(\"%s\", \"%s\")\n", tc_num++, responses, answers);
        printf("Expected:0\n");
        printf("Actual  :%d\n", get_score(responses, answers));
        printf("\n");
    }

    if (0) {
        char *responses = "A";
        char *answers = "A";    
        printf("Test %d  :get_score(\"%s\", \"%s\")\n", tc_num++, responses, answers);
        printf("Expected:100\n");
        printf("Actual  :%d\n", get_score(responses, answers));
        printf("\n");
    }

    if (0) {
        char *responses = "ABABD";
        char *answers = "ACDBD";    
        printf("Test %d  :get_score(\"%s\", \"%s\")\n", tc_num++, responses, answers);
        printf("Expected:60\n");
        printf("Actual  :%d\n", get_score(responses, answers));
        printf("\n");
    }

    /***   Secret test cases   ***/

    if (TC1) {
        tc_num = 1;
        double score = 2.5;

        char *responses = "DDDDD";
        char *answers = "DDDDD";    
        printf("Test %d  :get_score(\"%s\", \"%s\")\n", tc_num, responses, answers);
        printf("Expected:%d\n", expected_get_score(responses, answers));
        printf("Actual  :%d\n", get_score(responses, answers));
        printf("\n");
        
        if (expected_get_score(responses, answers) != get_score(responses, answers)) {
            score = 0;
        }
        printf("%s,%d,%.2f\n\n", __FILE__, tc_num, score);
    }

    if (TC2) {
        tc_num = 2;
        double score = 2.5;

        char *responses = "AAAD";
        char *answers = "AAAA";    
        printf("Test %d  :get_score(\"%s\", \"%s\")\n", tc_num, responses, answers);
        printf("Expected:%d\n", expected_get_score(responses, answers));
        printf("Actual  :%d\n", get_score(responses, answers));
        printf("\n");
        
        if (expected_get_score(responses, answers) != get_score(responses, answers)) {
            score = 0;
        }
        printf("%s,%d,%.2f\n\n", __FILE__, tc_num, score);
    }

    if (TC3) {
        tc_num = 3;
        double score = 2;

        char *responses = "AAAAD";
        char *answers = "DDDDD";    
        printf("Test %d  :get_score(\"%s\", \"%s\")\n", tc_num, responses, answers);
        printf("Expected:%d\n", expected_get_score(responses, answers));
        printf("Actual  :%d\n", get_score(responses, answers));
        printf("\n");
        
        if (expected_get_score(responses, answers) != get_score(responses, answers)) {
            score = 0;
        }
        printf("%s,%d,%.2f\n\n", __FILE__, tc_num, score);
    }
}