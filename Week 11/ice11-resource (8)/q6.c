#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node;

void print(node* ptr) {
    while (ptr != NULL) {
        printf("%d -> ", ptr->value);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

node* add(node *ptr, int value) {
    node* temp1 = malloc(sizeof(node));
    temp1->value = value;
    temp1->next = NULL;

    if (ptr == NULL) {
        ptr = temp1;
        return ptr;
    }

    node* temp2 = ptr;
    while (temp2->next != NULL) {
        temp2 = temp2->next;
    }

    temp2->next = temp1;

    return ptr;
}

int size(node* ptr) {
    int count = 0;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void free_linked_list(node* ptr) {
    while (ptr != NULL) {
        node* current = ptr; 
        ptr = ptr -> next;
        free(current);
    }
}

int main(void) {
    {
        node *head = NULL;
        head = add(head, 3);
        add(head, 4);
        add(head, 5);
        printf("Expected:3 -> 4 -> 5 -> NULL\n");
        printf("Actual  :");
        print(head);
        printf("Expected(size):3\n");
        printf("Actual  (size):%d\n", size(head));
        free_linked_list(head); // no test for free_linked_list
    }
}