#include <stdio.h>
#include <string.h>

int get_score(char responses[], char answers[]) {
    int n = strlen(responses);

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (responses[i] == answers[i]) {
            count++;
        }
    }

    return count * 100 / n;
}

int main(void) {
    int tc_num = 1;
    {
        char *responses = "AB";
        char *answers = "CD";    
        printf("Test %d  :get_score(\"%s\", \"%s\")\n", tc_num++, responses, answers);
        printf("Expected:0\n");
        printf("Actual  :%d\n", get_score(responses, answers));
        printf("\n");
    }

    {
        char *responses = "A";
        char *answers = "A";    
        printf("Test %d  :get_score(\"%s\", \"%s\")\n", tc_num++, responses, answers);
        printf("Expected:100\n");
        printf("Actual  :%d\n", get_score(responses, answers));
        printf("\n");
    }

    {
        char *responses = "ABABD";
        char *answers = "ACDBD";    
        printf("Test %d  :get_score(\"%s\", \"%s\")\n", tc_num++, responses, answers);
        printf("Expected:60\n");
        printf("Actual  :%d\n", get_score(responses, answers));
        printf("\n");
    }
}