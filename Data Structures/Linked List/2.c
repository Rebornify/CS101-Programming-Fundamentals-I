#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head;

void insert(int x, int n) {
    Node *temp1 = (Node *)malloc(sizeof(Node));
    temp1->data = x;

    if (n == 1) {
        temp1->next = head;
        head = temp1;
        return;
    }

    Node *temp2 = head;
    for (int i = 1; i < n - 1; i++) {
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}

void print() {
    Node *temp = head;
    printf("List is:");
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
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