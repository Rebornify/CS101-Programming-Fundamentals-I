#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char *name;
    int quantity;
    double price;
} inv_line_item;

typedef struct {
    char *name;
    int quantity;
} order_line_item;

double process_order(int inv_count, inv_line_item *inventory, int order_count, order_line_item *order) {
    for (int i = 0; i < order_count; i++) {
        bool is_found = false;
        // printf("%s ", order[i].name);
        for (int j = 0; j < inv_count; j++) {
            if (strcmp(order[i].name, inventory[j].name) == 0) {
                is_found = true;
                if(order[i].quantity > inventory[j].quantity) {
                    return false;
                }
            }
        }
        // printf("%s %s \n", order[i].name, is_found ? "true": "false");
        if (!is_found) {
            return false;
        }
    }

    // u can process it once you reach here
    double sum = 0;
    for (int i = 0; i < order_count; i++) {
        for (int j = 0; j < inv_count; j++) {
            if (strcmp(order[i].name, inventory[j].name) == 0) {
                inventory[j].quantity -= order[i].quantity;
                //printf("%lf \n", inventory[j].price * order[i].quantity);
                sum += inventory[j].price * order[i].quantity;
            }
        }
    }
    return sum;
}

int main(void) {
    int test_id = 0;

    {
        inv_line_item inventory[] = {{"apple", 3, 0.5}, {"orange", 4, 0.6}};
        order_line_item purchase[] = {{"apple", 3}};
        double result = process_order(sizeof(inventory)/sizeof(inv_line_item), inventory, sizeof(purchase)/sizeof(order_line_item), purchase);
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Expected return value:1.50\n");
        printf("Actual return value  :%.2lf\n", result);
        printf("Expected apple qty   :0\n");
        printf("Expected apple qty   :%d\n", inventory[0].quantity);
        printf("\n");
    }

    {
        inv_line_item inventory[] = {{"apple", 3, 0.5}, {"orange", 4, 0.6}, {"pear", 5, 0.7}};
        order_line_item purchase[] = {{"apple", 3}, {"banana", 3}};
        double result = process_order(sizeof(inventory)/sizeof(inv_line_item), inventory, sizeof(purchase)/sizeof(order_line_item), purchase);
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Expected return value:0.00\n");
        printf("Actual return value  :%.2lf\n", result);
        printf("Expected apple qty   :3\n");
        printf("Expected apple qty   :%d\n", inventory[0].quantity);
        printf("\n");
    }

    {
        inv_line_item inventory[] = {{"apple", 3, 0.5}, {"orange", 4, 0.6}, {"pear", 5, 0.7}};
        order_line_item purchase[] = {{"apple", 5}, {"orange", 3}};
        double result = process_order(sizeof(inventory)/sizeof(inv_line_item), inventory, sizeof(purchase)/sizeof(order_line_item), purchase);
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Expected return value:0.00\n");
        printf("Actual return value  :%.2lf\n", result);
        printf("Expected apple qty   :3\n");
        printf("Expected apple qty   :%d\n", inventory[0].quantity);
        printf("Expected orange qty  :4\n");
        printf("Expected orange qty  :%d\n", inventory[1].quantity);
        printf("\n");
    }

    {
        inv_line_item inventory[] = {{"apple", 3, 0.5}, {"orange", 4, 0.6}, {"pear", 5, 0.7}};
        order_line_item purchase[] = {{"apple", 3}, {"orange", 2}};
        double result = process_order(sizeof(inventory)/sizeof(inv_line_item), inventory, sizeof(purchase)/sizeof(order_line_item), purchase);
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Expected return value:2.70\n");
        printf("Actual return value  :%.2lf\n", result);
        printf("Expected apple qty   :0\n");
        printf("Expected apple qty   :%d\n", inventory[0].quantity);
        printf("Expected orange qty  :2\n");
        printf("Expected orange qty  :%d\n", inventory[1].quantity);
        printf("\n");
    }
}