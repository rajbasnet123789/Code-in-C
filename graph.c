#include <stdio.h>
#include <stdlib.h>

// Graph node structure
typedef struct graph {
    int data;
    int wt;
    struct graph* next;
} graph;
typedef struct edges{
    int src;
    int des;
    int wt;
    struct edges* next;
}edges;
// Create a new graph node
graph* create_graph(int data, int wt) {
    graph* temp = (graph*)malloc(sizeof(graph));
    temp->data = data;
    temp->wt = wt;
    temp->next = NULL;
    return temp;
}

// Insert a new edge into the adjacency list
void insert(graph** head, int data, int wt) {
    graph* temp = create_graph(data, wt);
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

// Read graph input
void readGraph(graph* Graph[], int n) {
    for (int i = 0; i < n; i++) {
        int k;
        printf("Enter the number of edges adjacent to vertex %d: ", i);
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int r, wt;
            printf("Enter the adjacent vertex and its weight: ");
            scanf("%d%d", &r, &wt);
            insert(&Graph[i], r, wt);
        }
    }
}

// Perform depth-first search (DFS)
void dfs(int node, graph* Graph[], int vis[]) {
    vis[node] = 1;
    printf("%d ", node);
    graph* p = Graph[node];
    while (p) {
        if (!vis[p->data]) {
            dfs(p->data, Graph, vis);
        }
        p = p->next;
    }
}

// Print the adjacency list representation of the graph
void printGraph(graph* Graph[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Adjacency list of vertex %d:\n", i);
        graph* temp = Graph[i];
        while (temp) {
            printf(" -> (%d, %d)", temp->data, temp->wt);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    int n;

    // Read the number of vertices
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    // Initialize the graph as an array of adjacency lists
    graph* Graph[n];
    for (int i = 0; i < n; i++) {
        Graph[i] = NULL;
    }

    // Read the graph input
    readGraph(Graph, n);

    // Print the adjacency list
    printf("\nGraph representation (Adjacency List):\n");
    printGraph(Graph, n);

    // Perform DFS
    int vis[n];
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
    }

    printf("\nDepth First Search (DFS) starting from vertex 0:\n");
    dfs(0, Graph, vis);

    return 0;
}
