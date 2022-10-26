#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *insert(node *head, int data) {
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
    return head;
}

void print(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse_print(node *head) {
    if (head == NULL) {
        return;
    }
    reverse_print(head->next);
    printf("%d ", head->data);
}

void free_all_nodes (node *ptr) {
    while (ptr != NULL) {
        node *current = ptr;
        ptr = ptr->next;
        free(current);

    }
}

int main() {
    node *head = NULL;
    head = insert(head, 2);
    head = insert(head, 4);
    head = insert(head, 6);
    head = insert(head, 5);
    print(head);

    reverse_print(head);
    printf("\n");
    free_all_nodes(head);
}