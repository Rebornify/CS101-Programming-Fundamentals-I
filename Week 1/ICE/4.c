#include <stdio.h>

int main(void) {
    int sec;
    printf("Enter time in seconds:");
    scanf("%d", &sec);

    int h = sec / 3600;
    int m = (sec - h * 3600) / 60;
    int s = sec - (h * 3600) - (m * 60);

    printf("%d seconds is %02d:%02d:%02d (HH:MM:SS)\n", sec, h, m, s);
}