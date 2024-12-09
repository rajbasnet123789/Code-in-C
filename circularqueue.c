#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
    int data;
    struct node *next;
} node;


typedef struct stack {
    node *top;
} stack;


node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}


stack *create_stack() {
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = NULL;
    return s;
}


void push(stack *s, int data) {
    node *new_node = create_node(data);
    new_node->next = s->top;
    s->top = new_node;
}


int pop(stack *s) {
    if (s->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = s->top->data;
    node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    return data;
}


bool is_empty(stack *s) {
    return s->top == NULL;
}


int size(stack *s) {
    int count = 0;
    node *temp = s->top;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}


void display(stack *s) {
    node *temp = s->top;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    stack *s = create_stack();
    
    int choice, data;
    printf("Input:\n Press:\n 1 Push\n 2 Pop\n  3 Size\n 4 Exit\n");
    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                push(s, data);
                printf("Stack - ");
                display(s);
                break;
            case 2:
                data = pop(s);
                if (data != -1) {
                    printf("Popped element - %d\n", data);
                    printf("Stack after pop - ");
                    display(s);
                }
                break;
            case 3:
                printf("Size of stack: %d\n", size(s));
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
