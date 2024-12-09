#include <stdio.h>
#include <stdlib.h>

// Definition for the Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* create_node(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to insert a node at the end of the list
void insert(Node** head, int data) {
    Node* temp = create_node(data);
    if (*head == NULL) {
        *head = temp;
        return;
    }
    Node* temp2 = *head;
    while (temp2->next) {
        temp2 = temp2->next;
    }
    temp2->next = temp;
}

// Function to split the list into two based on even and odd positions
void split(Node** P, Node** Q, Node** R) {
    if ((*P) == NULL) {
        return;
    }
    int index = 1;
    Node* current = *P;
    while (current) {
        if (index % 2 == 0) {
            insert(Q, current->data);
        } else {
            insert(R, current->data);
        }
        current = current->next;
        index++;
    }
}

// Function to display the list
void display(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function for menu-driven operations
int main() {
    Node* P = NULL; // Original list
    Node* Q = NULL; // List for even positions
    Node* R = NULL; // List for odd positions
    int choice, data;
    printf("\nMenu:\n");
        printf("1. Insert into original list\n");
        printf("2. Display original list\n");
        printf("3. Split the list\n");
        printf("4. Display even-position list\n");
        printf("5. Display odd-position list\n");
        printf("6. Exit\n");
    while (1) {
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&P, data);
                break;
            case 2:
                printf("Original list: ");
                display(P);
                break;
            case 3:
                split(&P, &Q, &R);
                printf("List has been split into even and odd positions.\n");
                break;
            case 4:
                printf("Even-position list: ");
                display(Q);
                break;
            case 5:
                printf("Odd-position list: ");
                display(R);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
