#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void insert(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = head;
    head = temp;
}

void print() {
    struct Node* temp = head;
    printf("List is: ");
    while (temp != NULL) {
        printf(" %d", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int main(void) {
    head = NULL;

    int n;
    printf("How many numbers?\n");
    scanf("%d", &n);

    int x;
    for (int i = 0; i < n; i++) {
        printf("Enter a number:\n");
        scanf("%d", &x);
        insert(x);
        print();
    }
}