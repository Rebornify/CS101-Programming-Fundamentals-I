#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node;

node *head;

void insert(int x) {
    node *temp = malloc(sizeof(node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void print() {
    node *temp = head;
    printf("List is: ");
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
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