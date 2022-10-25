#include <stdio.h>

int main(void) {
    int tc_num = 1;
    {
        printf("Test %d  :get_hashtags(\"You #jump I jump\")\n", tc_num++);
        printf("Expected:#jump\n");
        printf("Actual  :");
        int n;
        char **result = get_hashtags("You #jump I leap", &n);
        for (int i = 0; i < n; i++) {
            printf("%s ", result[i]);
            free(result[i]);
        }
        free(result);
        printf("\n");
        printf("\n");
    }

    {
        printf("Test %d  :get_hashtags(\"There is no hashtag\")\n", tc_num++);
        printf("Expected:0 true\n");
        int n;
        char **result = get_hashtags("There is no hashtag", &n);
        printf("Actual  :%d %s", n, result == NULL ? "true" : "false");
        printf("\n");
        printf("\n");
    }

    {
        printf("Test %d  :get_hashtags(\"#tag1-#tag2-#tag3-#tag4\")\n", tc_num++);
        printf("Expected:#tag1 #tag2 #tag3 #tag4\n");
        int n;
        char **result = get_hashtags("#tag1-#tag2-#tag3-#tag4", &n);
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%s ", result[i]);
            free(result[i]);
        }
        free(result);
        printf("\n");
        printf("\n");
    }

    {
        printf("Test %d  :get_hashtags(\"#War&Peace #WarAndPeace.\")\n", tc_num++);
        printf("Expected:#War #WarAndPeace\n");
        int n;
        char **result = get_hashtags("#War&Peace #WarAndPeace.", &n);
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%s ", result[i]);
            free(result[i]);
        }
        free(result);
        printf("\n");
        printf("\n");
    }

    {
        printf("Test %d  :get_hashtags(\"#12##34#1for1#COVID\")\n", tc_num++);
        printf("Expected:#1for1 #COVID\n");
        int n;
        char **result = get_hashtags("#12##34#1for1#COVID", &n);
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%s ", result[i]);
            free(result[i]);
        }
        free(result);
        printf("\n");
        printf("\n");
    }
}