#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node;


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