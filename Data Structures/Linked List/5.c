#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *insert(Node *head, int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        Node *temp1 = head;
        while (temp1->next != NULL) {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse_print(Node *head) {
    if (head == NULL) {
        return;
    }
    reverse_print(head->next);
    printf("%d ", head->data);
}

void free_all_nodes (Node *ptr) {
    while (ptr != NULL) {
        Node *current = ptr;
        ptr = ptr->next;
        free(current);

    }
}

int main() {
    Node *head = NULL;
    head = insert(head, 2);
    head = insert(head, 4);
    head = insert(head, 6);
    head = insert(head, 5);
    print(head);

    reverse_print(head);
    printf("\n");
    free_all_nodes(head);
}