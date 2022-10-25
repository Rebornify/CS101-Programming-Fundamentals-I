// Name :
// Email:

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DO NOT MODIFY the struct definition
typedef struct citizen {
    char *name;
    int age;
    struct citizen *next;
} citizen;
// DO NOT MODIFY the struct definition


void move_to_priority(citizen **queue, citizen **priority_queue) {

}

// DO NOT MODIFY THE CODE BELOW!
void print_queue(citizen *queue) {
    citizen *ptr = queue;
    while (ptr != NULL) {
        printf("%s -> ", ptr->name);
        ptr = ptr->next;
    }
    puts("NULL");
}


int main(void) {
    int tc_num = 1;

    {
        citizen daniel = {"daniel", 35, NULL};
        citizen charlie = {"charlie", 36, &daniel};
        citizen ben = {"ben", 25, &charlie};
        citizen adeline = {"adeline", 21, &ben};
        citizen *start = &adeline;
        citizen *priority = NULL;
        printf("Test Case %d\n", tc_num++);
        move_to_priority(&start, &priority);
        printf("Expected(queue)         :adeline -> ben -> charlie -> daniel -> NULL\n");
        printf("Expected(priority queue):NULL\n");
        printf("Actual(queue)           :");
        print_queue(start);
        printf("Actual(priority queue)  :");
        print_queue(priority);
        printf("\n");
    }

    {
        citizen daniel = {"daniel", 35, NULL};
        citizen charlie = {"charlie", 66, &daniel};
        citizen ben = {"ben", 65, &charlie};
        citizen adeline = {"adeline", 21, &ben};
        citizen *start = &adeline;
        citizen *priority = NULL;
        printf("Test Case %d\n", tc_num++);
        move_to_priority(&start, &priority);
        printf("Expected(queue)         :adeline -> daniel -> NULL\n");
        printf("Expected(priority queue):ben -> charlie -> NULL\n");
        printf("Actual(queue)           :");
        print_queue(start);
        printf("Actual(priority queue)  :");
        print_queue(priority);
        printf("\n");
    }

    {
        citizen elise = {"elise", 80, NULL};
        citizen daniel = {"daniel", 65, NULL};
        citizen charlie = {"charlie", 26, &daniel};
        citizen ben = {"ben", 22, &charlie};
        citizen adeline = {"adeline", 66, &ben};
        citizen *start = &adeline;
        citizen *priority = &elise;
        printf("Test Case %d\n", tc_num++);
        move_to_priority(&start, &priority);
        printf("Expected(queue)         :ben -> charlie -> NULL\n");
        printf("Expected(priority queue):elise -> adeline -> daniel -> NULL\n");
        printf("Actual(queue)           :");
        print_queue(start);
        printf("Actual(priority queue)  :");
        print_queue(priority);
        printf("\n");
    }

    {
        citizen adeline = {"adeline", 66, NULL};
        citizen *start = &adeline;
        citizen *priority = NULL;
        printf("Test Case %d\n", tc_num++);
        move_to_priority(&start, &priority);
        printf("Expected(queue)         :NULL\n");
        printf("Expected(priority queue):adeline -> NULL\n");
        printf("Actual(queue)           :");
        print_queue(start);
        printf("Actual(priority queue)  :");
        print_queue(priority);
        printf("\n");
    }

    {
        citizen billy = {"billy", 67, NULL};
        citizen adeline = {"adeline", 66, &billy};
        citizen *start = &adeline;
        citizen *priority = NULL;
        printf("Test Case %d\n", tc_num++);
        move_to_priority(&start, &priority);
        printf("Expected(queue)         :NULL\n");
        printf("Expected(priority queue):adeline -> billy -> NULL\n");
        printf("Actual(queue)           :");
        print_queue(start);
        printf("Actual(priority queue)  :");
        print_queue(priority);
        printf("\n");
    }


    {
        citizen billy = {"billy", 17, NULL};
        citizen adeline = {"adeline", 16, &billy};
        citizen *start = &adeline;
        citizen *priority = NULL;
        printf("Test Case %d\n", tc_num++);
        move_to_priority(&start, &priority);
        printf("Expected(queue)         :adeline -> billy -> NULL\n");
        printf("Expected(priority queue):NULL\n");
        printf("Actual(queue)           :");
        print_queue(start);
        printf("Actual(priority queue)  :");
        print_queue(priority);
        printf("\n");
    }



    {
        citizen *start = NULL;
        citizen adeline = {"adeline", 96, NULL};
        citizen *priority = &adeline;
        printf("Test Case %d\n", tc_num++);
        move_to_priority(&start, &priority);
        printf("Expected(queue)         :NULL\n");
        printf("Expected(priority queue):adeline -> NULL\n");
        printf("Actual(queue)           :");
        print_queue(start);
        printf("Actual(priority queue)  :");
        print_queue(priority);
        printf("\n");
    }
}