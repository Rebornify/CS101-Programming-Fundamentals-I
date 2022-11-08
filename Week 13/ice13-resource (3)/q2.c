#include <stdio.h>
#include <string.h>

void trim(char sentence[]) {
    char* back = sentence + strlen(sentence) - 1;

    while(*back == ' ') {
        back--;
    }

    *(back + 1) = '\0';

    char* front = sentence;
    char* content_ptr = front;

    while (*content_ptr == ' ') {
        content_ptr++;
    }

    while (*content_ptr != '\0') {
        *front++ = *content_ptr++;
    }

    *front = '\0';
}

int main(void) {
    {
        char sentence[] = "    apple and orange";
        trim(sentence);
        printf("Test 1\n");
        printf("Expected:[apple and orange]\n");
        printf("Actual  :[%s]\n", sentence); 
        printf("\n");  
    }

    {
        char sentence[] = "apple and orange          ";
        trim(sentence);
        printf("Test 2\n");
        printf("Expected:[apple and orange]\n");
        printf("Actual  :[%s]\n", sentence); 
        printf("\n");  
  
    }

    {
        char sentence[] = "       apple and orange          ";
        trim(sentence);
        printf("Test 3\n");
        printf("Expected:[apple and orange]\n");
        printf("Actual  :[%s]\n", sentence);   
    }
}