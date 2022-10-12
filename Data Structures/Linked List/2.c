#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

void insert(int x, int n) {
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1 -> data = x;

    if (n == 1) {
        temp1 -> next = head;
        head = temp1;
        return;
    }

    struct Node* temp2 = head;
    for (int i = 1; i < n - 1; i++) {
        temp2 = temp2 -> next;
    }

    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;
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
    insert(2, 1);
    insert(3, 2);
    insert(4, 1);
    insert(5, 2);
    print();
}