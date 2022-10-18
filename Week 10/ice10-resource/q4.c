#include <stdio.h>

typedef struct {
    char name[100];
    int age;
    char gender; // either 'M' or 'F'
} person;

person get_youngest_female(person all[], int n) {
    person youngest = all[0];
    for (int i = 1; i < n; i++) {
        if (all[i].age < youngest.age && all[i].gender == 'F') {
            youngest = all[i];
        }
    }
    return youngest;
}

int main(void) {
    {
        person all[] = {
            {"Shaun", 38, 'M'},
            {"Leslie", 34, 'M'},
            {"Dean", 32, 'M'},
            {"Sebastian", 18, 'M'},
            {"Gabriel", 19, 'M'},
            {"Xiao Wei", 38, 'F'},
            {"Cheryl", 17, 'F'},
            {"Sunita", 14, 'F'},
            {"Jolene", 13, 'F'},
            {"Jiwen", 19, 'F'},
            {"Amanda", 38, 'F'}};

        person youngest = get_youngest_female(all, sizeof(all) / sizeof(person));
        printf("Test 1\n");
        printf("Expected:Jolene\n");
        printf("Actual  :%s\n", youngest.name);
        printf("\n");
    }

    {
        person all[] = {
            {"Leslie", 34, 'M'},
            {"Dean", 32, 'M'},
            {"Sebastian", 18, 'M'},
            {"Gabriel", 19, 'M'},
            {"Xiao Wei", 38, 'F'},
            {"Cheryl", 17, 'F'},
            {"Sunita", 14, 'F'},
            {"Jolene", 13, 'F'},
            {"Jiwen", 19, 'F'},
            {"Vienne", 8, 'F'},
            {"Sue", 8, 'F'}};

        person youngest = get_youngest_female(all, sizeof(all) / sizeof(person));
        printf("Test 2\n");
        printf("Expected:Vienne\n");
        printf("Actual  :%s\n", youngest.name);
        printf("\n");
    }

    {
        person all[] = {
            {"Amy", 4, 'F'},
            {"Dean", 32, 'M'},
            {"Sebastian", 18, 'M'},
            {"Gabriel", 19, 'M'},
            {"Xiao Wei", 38, 'F'},
            {"Cheryl", 17, 'F'},
            {"Sunita", 14, 'F'},
            {"Jolene", 13, 'F'},
            {"Jiwen", 19, 'F'},
            {"Amanda", 38, 'F'},
            {"Zac", 39, 'M'}};

        person youngest = get_youngest_female(all, sizeof(all) / sizeof(person));
        printf("Test 3\n");
        printf("Expected:Amy\n");
        printf("Actual  :%s \n", youngest.name);
        printf("\n");
    }
}