#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for graph node
typedef struct graph {
    int data;
    int wt;
    struct graph* next;
} graph;

// Definition for edge node
typedef struct edge {
    int src;
    int des;
    int wt;
    struct edge* next;
} edge;

// Function to create a new graph node
graph* create_graph_node(int data, int wt) {
    graph* temp = (graph*)malloc(sizeof(graph));
    temp->data = data;
    temp->wt = wt;
    temp->next = NULL;
    return temp;
}

// Function to create a new edge node
edge* create_edge_node(int src, int des, int wt) {
    edge* temp = (edge*)malloc(sizeof(edge));
    temp->src = src;
    temp->des = des;
    temp->wt = wt;
    temp->next = NULL;
    return temp;
}

// Function to add a node into the graph in sorted order based on weight
void addEdgeSort(edge** head, int src, int wt, int des) {
    edge* temp = create_edge_node(src, des, wt);
    
    // Check if the list is empty or if the new node should be the first node
    if (*head == NULL || (*head)->wt > temp->wt) {
        temp->next = *head;
        *head = temp;
        return;
    }
    
    // Find the correct position to insert the new node
    edge* temp2 = *head;
    while (temp2->next != NULL && temp2->next->wt < temp->wt) {
        temp2 = temp2->next;
    }
    
    // Insert the new node at the correct position
    temp->next = temp2->next;
    temp2->next = temp;
}

// Function to insert a node into the graph
void insert(graph** head, int data, int wt) {
    graph* temp = create_graph_node(data, wt);
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
            int wt;
            printf("Enter the adjacent vertex: ");
            scanf("%d", &y);
            printf("Enter its weight: ");
            scanf("%d", &wt);
            insert(&Graph[i], y, wt);
        }
    }
}

// Function to display the graph
void displayGraph(graph* Graph[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i);
        graph* temp = Graph[i];
        while (temp) {
            printf("%d (%d) -> ", temp->data, temp->wt);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Function to add edges from the adjacency list to a sorted edge list
void addGraphEdges(graph* Graph[], int n, edge** head) {
    for (int i = 0; i < n; i++) {
        graph* p = Graph[i];
        while (p) {
            addEdgeSort(head, i, p->wt, p->data);
            p = p->next;
        }
    }
}

// Function to display the edges in the sorted list
void displayEdges(edge* head) {
    while (head) {
        printf("Source: %d, Destination: %d, Weight: %d -> ", head->src, head->des, head->wt);
        head = head->next;
    }
    printf("NULL\n");
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

    edge* edgeList = NULL;
    printf("\nMenu:\n");
        printf("1. Read Graph\n");
        printf("2. Display Graph\n");
        printf("3. Sort Edges\n");
        printf("4. Display Edges\n");
        printf("5. Exit\n");
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
                edgeList = NULL; // Reset edge list before sorting
                addGraphEdges(Graph, n, &edgeList);
                break;
            case 4:
                displayEdges(edgeList);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
