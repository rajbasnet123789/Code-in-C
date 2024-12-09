#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Define the structure for a tree node
typedef struct tree {
    int data;
    struct tree* left;
    struct tree* right;
} tree;

// Define the structure for a queue
typedef struct queue {
    tree** arr;  // Array of pointers to tree nodes
    int size;
    int front;
    int rear;
} queue;

// Create a queue
queue* create_queue() {
    queue* q = (queue*)malloc(sizeof(queue));
    q->arr = (tree**)malloc(sizeof(tree*) * MAX);
    q->front = -1;
    q->rear = -1;
    q->size = MAX;
    return q;
}

// Enqueue a tree node
void enqueue(queue* q, tree* node) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->arr[++(q->rear)] = node;
}

// Dequeue a tree node
tree* dequeue(queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
        return NULL;
    }
    return q->arr[(q->front)++];
}

// Check if the queue is empty
int is_empty(queue* q) {
    return q->front == -1 || q->front > q->rear;
}

// Create a new tree node
tree* create_tree(int data) {
    tree* temp = (tree*)malloc(sizeof(tree));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert a node into the BST
tree* insert(tree* root, int data) {
    if (root == NULL) {
        return create_tree(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Perform level order traversal
void level_order(tree* root) {
    if (root == NULL) {
        return;
    }
    queue* q = create_queue();
    enqueue(q, root);
    while (!is_empty(q)) {
        tree* temp = dequeue(q);
        printf("%d ", temp->data);
        if (temp->left) {
            enqueue(q, temp->left);
        }
        if (temp->right) {
            enqueue(q, temp->right);
        }
    }
    printf("\n");
}

// Find the in-order successor
tree* inorder_successor(tree* root) {
    tree* curr = root->right;
    while (curr && curr->left) {
        curr = curr->left;
    }
    return curr;
}

// Delete a node from the BST
tree* delete(tree* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL) {
            tree* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            tree* temp = root->left;
            free(root);
            return temp;
        }

        tree* temp = inorder_successor(root);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    return root;
}

// Find the height of the tree
int height(tree* root) {
    if (root == NULL) {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

// Mirror the tree
tree* mirror(tree* root) {
    if (root == NULL) {
        return root;
    }
    tree* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);

    return root;
}

// Perform in-order traversal
void inorder(tree* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Compute ancestors for each node
void ancestor(tree* root, tree** parent) {
    if (root == NULL) {
        return;
    }

    if (root->left) {
        parent[root->left->data] = root;  // Store parent of left child
        ancestor(root->left, parent);
    }

    if (root->right) {
        parent[root->right->data] = root;  // Store parent of right child
        ancestor(root->right, parent);
    }
}

// Find the lowest common ancestor (LCA)
tree* lca(tree* root, tree* p, tree* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }
    tree* left = lca(root->left, p, q);
    tree* right = lca(root->right, p, q);
    if (left == NULL) {
        return right;
    } else if (right == NULL) {
        return left;
    } else {
        return root;
    }
}

// Main function
int main() {
    tree* root = NULL;

    // Insert nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 150);

    printf("In-order Traversal of Original Tree: ");
    inorder(root);
    printf("\n");

    // Delete a node
    root = delete(root, 50);
    printf("In-order Traversal after Deleting 50: ");
    inorder(root);
    printf("\n");

    // Mirror the tree
    root = mirror(root);
    printf("In-order Traversal of Mirrored Tree: ");
    inorder(root);
    printf("\n");

    // Initialize an array to store parent pointers
    tree* parent[100] = {NULL};  // Assuming node values are less than 100

    // Compute ancestors for all nodes
    ancestor(root, parent);

    // Print ancestors for specific nodes
    int query[] = {20, 40, 150};
    int num_queries = sizeof(query) / sizeof(query[0]);

    for (int i = 0; i < num_queries; i++) {
        int node_value = query[i];
        printf("Ancestors of %d: ", node_value);
        tree* current = parent[node_value];
        while (current) {
            printf("%d ", current->data);
            current = parent[current->data];
        }
        printf("\n");
    }

    // Level order traversal
    printf("Level Order Traversal: ");
    level_order(root);

    return 0;
}
