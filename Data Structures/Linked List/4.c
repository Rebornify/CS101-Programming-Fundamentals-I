#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head;

void insert(int data) {
    node *temp = malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        node *temp1 = head;
        while (temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
}

void print() {
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse() {
    node *prev = NULL;
    node *next;
    node *current = head;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    head = NULL;
    insert(2);
    insert(4);
    insert(6);
    insert(8);
    print();
    
    reverse();
    print();
}