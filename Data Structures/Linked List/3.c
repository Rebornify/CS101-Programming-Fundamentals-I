#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* head;

void insert(int data) {
    struct Node* temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = data;

    if (head == NULL) {
        temp1->next = head;
        head = temp1;
        return;
    }

    struct Node* temp2 = head;
    while (temp2 -> next != NULL) {
        temp2 = temp2 -> next;
    }

    temp1 -> next = temp2->next;
    temp2 -> next = temp1;
}

void print() {
    printf("List is: ");

    struct Node* temp = head;
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete(int n) {
    struct Node* temp1 = head;

    if (n == 1) {
        head = temp1 -> next;
        free(temp1);
        return;
    }

    for (int i = 1; i < n - 1; i++) {
        temp1 = temp1 -> next;
    }

    struct Node* temp2 = temp1 -> next;
    temp1 -> next = temp2 -> next;

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