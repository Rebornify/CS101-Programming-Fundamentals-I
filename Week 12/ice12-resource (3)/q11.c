#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_valid(char email[]) {
    char *domain = "@smu.edu.sg";
    char *needle = strstr(email, domain);

    if (needle == NULL) {
        return false;
    }

    int needle_len = strlen(needle);
    int email_len = strlen(email);
    
    if (needle_len != strlen(domain) || needle_len == email_len) {
        return false;
    }

    int count = 0;
    while (*email) {
        if (*email == '@') {
            count++;
        }
        email++;
    }

    if (count != 1) {
        return false;
    }
    
    return true;
}

int main(void) 
{
    char email[18];
    printf("Please enter your SMU email address:");
    scanf("%s", email);

    while (!is_valid(email)) {
        printf("Invalid!\n");
        printf("Please enter a valid SMU email address:");
        scanf("%s", email);
    }
    printf("Thanks!\n");
}