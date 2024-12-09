#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node {
    int emp_id;
    char *name;
    struct node *next;
} node;

// Function to create a new node
node* create_node(int emp_id, char *name) {
    node *temp = (node*)malloc(sizeof(node));
    temp->emp_id = emp_id;
    temp->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
    strcpy(temp->name, name);
    temp->next = NULL;
    return temp;
}

// Function to insert a new node at the end of the list
void insert(node **head, int emp_id, char *name) {
    node *temp = create_node(emp_id, name);
    if (*head == NULL) {
        *head = temp;
    } else {
        node *last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = temp;
    }
}

// Function to check if a node is present in the list
bool ispresent(node *head, int emp_id, char *name) {
    while (head != NULL) {
        if (head->emp_id == emp_id && strcmp(head->name, name) == 0) {
            return true;
        }
        head = head->next;
    }
    return false;
}

// Function to get the union of two linked lists
node* unionlists(node **head1, node **head2) {
    node *unionList = NULL;
    node *current = *head1;

    // Add all nodes from the first list
    while (current != NULL) {
        if (!ispresent(unionList, current->emp_id, current->name)) {
            insert(&unionList, current->emp_id, current->name);
        }
        current = current->next;
    }

    // Add all nodes from the second list
    current = *head2;
    while (current != NULL) {
        if (!ispresent(unionList, current->emp_id, current->name)) {
            insert(&unionList, current->emp_id, current->name);
        }
        current = current->next;
    }

    return unionList;
}

// Function to print the linked list
void printList(node *head) {
    while (head != NULL) {
        printf("Emp_ID: %d, Name: %s -> ", head->emp_id, head->name);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function for menu-driven operations
int main() {
    node *list1 = NULL;
    node *list2 = NULL;
    node *unionList = NULL;

    int choice, emp_id;
    char name[100];
     printf("\nMenu:\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Find Union\n");
        printf("6. Display Union\n");
        printf("7. Exit\n");
    while (1) {
       
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Employee ID: ");
                scanf("%d", &emp_id);
                printf("Enter Employee Name: ");
                scanf("%s", name);
                insert(&list1, emp_id, name);
                break;
            case 2:
                printf("Enter Employee ID: ");
                scanf("%d", &emp_id);
                printf("Enter Employee Name: ");
                scanf("%s", name);
                insert(&list2, emp_id, name);
                break;
            case 3:
                printf("List 1: ");
                printList(list1);
                break;
            case 4:
                printf("List 2: ");
                printList(list2);
                break;
            case 5:
                unionList = unionlists(&list1, &list2);
                printf("Union of List 1 and List 2 has been created.\n");
                break;
            case 6:
                printf("Union List: ");
                printList(unionList);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
