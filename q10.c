#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

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

// Definition for the queue structure
typedef struct queue {
    int* arr;
    int front;
    int rear;
    int size;
} queue;

// Function to create a new queue
queue* create_queue() {
    queue* temp = (queue*)malloc(sizeof(queue));
    temp->front = -1;
    temp->rear = -1;
    temp->size = MAX;
    temp->arr = (int*)malloc(sizeof(int) * MAX);
    return temp;
}

// Function to enqueue an element into the queue
void enqueue(queue* q, int data) {
    if (q->rear == q->size - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->arr[++(q->rear)] = data;
}

// Function to dequeue an element from the queue
int dequeue(queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = q->arr[q->front++];
    if (q->front > q->rear) {
        q->front = q->rear = -1; // Reset queue
    }
    return data;
}

// Function to check if the queue is empty
bool is_empty(queue* q) {
    return q->front == -1;
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

// Function to perform Breadth-First Search (BFS)
void bfs(graph* Graph[], int n) {
    queue* q = create_queue();
    enqueue(q, 0);
    int vis[n];
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
    }
    vis[0] = 1;

    while (!is_empty(q)) {
        int node = dequeue(q);
        printf("%d ", node);
        graph* temp = Graph[node];
        while (temp) {
            if (!vis[temp->data]) {
                enqueue(q, temp->data);
                vis[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
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
    printf("\nMenu:\n");
        printf("1. Read Graph\n");
        printf("2. Display Graph\n");
        printf("3. Perform BFS\n");
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
                bfs(Graph, n);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
