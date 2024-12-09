#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for graph node
typedef struct node {
    int data;
    struct node* next;
} graph;

// Function to create a new graph node
graph* create_list(int data) {
    graph* temp = (graph*)malloc(sizeof(graph));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to insert a node into the graph
void insert(graph** head, int data) {
    graph* temp = create_list(data);
    if (*head == NULL) {
        *head = temp;
        return;
    }
    graph* temp2 = *head;
    while (temp2->next) {
        temp2 = temp2->next;
    }
    temp2->next = temp;
}

// Function to read the graph
void readGraph(graph* Graph[], int n) {
    for (int i = 0; i < n; i++) {
        int k;
        printf("Enter the number of edges adjacent to vertex %d: ", i);
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int y;
            printf("Enter the adjacent vertex: ");
            scanf("%d", &y);
            insert(&Graph[i], y);
        }
    }
}

// Function to display the graph
void displayGraph(graph* Graph[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i);
        graph* temp = Graph[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to perform Depth-First Search (DFS)
void dfs(int i, graph *Graph[], int vis[]) {
    vis[i] = 1;
    printf("%d ", i);
    graph *temp = Graph[i];
    while (temp) {
        if (!vis[temp->data]) {
            dfs(temp->data, Graph, vis);
        }
        temp = temp->next;
    }
}

// Main function for menu-driven operations
int main() {
    int n, choice;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    graph* Graph[n];
    for (int i = 0; i < n; i++) {
        Graph[i] = NULL;
    }
    int vis[n];


    printf("\nMenu:\n");
    printf("1. Read Graph\n");
    printf("2. Display Graph\n");
    printf("3. Perform DFS\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readGraph(Graph, n);
                break;
            case 2:
                displayGraph(Graph, n);
                break;
            case 3:
                {
                    int source;
                    printf("Enter the source vertex for DFS: ");
                    scanf("%d", &source);
                    if (source < 0 || source >= n) {
                        printf("Invalid source vertex! Please enter a valid vertex.\n");
                    } else {
                        // Reset the visited array before performing DFS
                        for (int i = 0; i < n; i++) {
                            vis[i] = 0;
                        }
                        dfs(source, Graph, vis);
                        printf("\n");
                    }
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
