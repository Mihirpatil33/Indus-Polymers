#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Structure to represent an item
struct Item {
    char name[50];
    float price;
};

// Stack structure
struct Stack {
    struct Item items[MAX_ITEMS];
    int top;
};

// Function to initialize the stack
void initializeStack(struct Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *s) {
    return s->top == MAX_ITEMS - 1;
}

// Function to push an item onto the stack
void push(struct Stack *s, struct Item item) {
    if (isFull(s)) {
        printf("Cart is full. Cannot add more items.\n");
        return;
    }
    s->items[++s->top] = item;
    printf("%s added to the cart. Total items in the cart: %d\n", item.name, s->top + 1);
}

// Function to pop an item from the stack
void pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Cart is empty. Nothing to remove.\n");
        return;
    }
    printf("Removed %s from the cart. Total items in the cart: %d\n", s->items[s->top].name, s->top);
    s->top--;
}

int main() {
    struct Stack cart;
    initializeStack(&cart);

    while (1) {
        printf("Options:\n");
        printf("1. Add item to cart\n");
        printf("2. Remove item from cart\n");
        printf("3. Quit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            struct Item item;
            printf("Enter the name of the item: ");
            scanf("%s", item.name);
            printf("Enter the price of the item: ");
            scanf("%f", &item.price);
            push(&cart, item);
        } else if (choice == 2) {
            pop(&cart);
        } else if (choice == 3) {
            printf("Thank you for shopping!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
