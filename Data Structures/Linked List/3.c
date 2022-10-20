#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head;

void insert(int data) {
    Node *temp1 = (Node *)malloc(sizeof(Node));
    temp1->data = data;

    if (head == NULL) {
        temp1->next = head;
        head = temp1;
        return;
    }

    Node *temp2 = head;
    while (temp2->next != NULL) {
        temp2 = temp2->next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}

void print() {
    printf("List is:");

    Node *temp = head;
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete(int n) {
    Node *temp1 = head;

    if (n == 1) {
        head = temp1->next;
        free(temp1);
        return;
    }

    for (int i = 0; i < n - 2; i++) {
        temp1 = temp1->next;
    }

    Node *temp2 = temp1->next;
    temp1->next = temp2->next;

    free(temp2);
}

int main() {
    head = NULL;
    insert(2);
    insert(4);
    insert(6);
    insert(5);
    print();

    int n;
    printf("Enter a position: ");
    scanf("%d", &n);

    delete(n);
    print();
}