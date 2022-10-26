#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head;

void insert(int x, int n) {
    node *temp1 = malloc(sizeof(node));
    temp1->data = x;

    if (n == 1) {
        temp1->next = head;
        head = temp1;
        return;
    }

    node *temp2 = head;
    for (int i = 1; i < n - 1; i++) {
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}

void print() {
    node *temp = head;
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