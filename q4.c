#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
typedef struct tree {
    int data;
    struct tree* left;
    struct tree* right;
} tree;

// Function to create a new node with given data.
tree* create_tree(int data) {
    tree* temp = (tree*)malloc(sizeof(tree));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to insert a new node with given key in the BST.
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

// Function to find the inorder predecessor of a node.
int inorderprec(tree* root) {
    tree* curr = root->right;
    while (curr && curr->left != NULL) {
        curr = curr->left;
    }
    return curr->data;
}

// Function to delete a node with given key in the BST.
tree* delete_(tree* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data < root->data) {
        root->left = delete_(root->left, data);
    } else if (data > root->data) {
        root->right = delete_(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            tree* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            tree* temp = root->left;
            free(root);
            return temp;
        } else {
            int x = inorderprec(root);
            root->data = x;
            root->right = delete_(root->right, x);
        }
    }
    return root;
}

// Function to find the height of the BST.
int height(tree* root) {
    if (root == NULL) {
        return 0;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    return (leftheight > rightheight ? leftheight : rightheight) + 1;
}

// Function to find the smallest element in the BST.
int smallest(tree* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root ? root->data : -1;  // Return -1 if the tree is empty.
}

// Function to find nodes with both left and right children.
void find_common_parent(tree* root, int* c) {
    if (root == NULL) {
        return;
    }
    if (root->left != NULL && root->right != NULL) {
        printf("Parent Node: %d, ", root->data);
        printf("Left Child: %d, ", root->left->data);
        printf("Right Child: %d\n", root->right->data);
        (*c)++;
    }
    find_common_parent(root->left, c);
    find_common_parent(root->right, c);
}

// Function to count nodes on the right-hand side.
void right_hand(tree* root, int* d) {
    while (root->right != NULL) {
        root = root->right;
        (*d)++;
    }
}

// Inorder traversal of the BST.
void inorder(tree* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d  ", root->data);
    inorder(root->right);
}

int main() {
    tree* root = NULL;
    int choice, data, count = 0, depth = 0;
    
    printf("\n\nMenu:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Find Height\n");
    printf("4. Find Common Parent Nodes\n");
    printf("5. Count Nodes on Right-hand Side\n");
    printf("6. Find Smallest Element\n");
    printf("7. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Node inserted.\n");
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = delete_(root, data);
                printf("Node deleted.\n");
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Height of the BST: %d\n", height(root));
                break;

            case 4:
                count = 0;
                find_common_parent(root, &count);
                printf("Total number of nodes with both left and right children: %d\n", count);
                break;

            case 5:
                depth = 0;
                right_hand(root, &depth);
                printf("Total number of nodes on the right-hand side: %d\n", depth);
                break;

            case 6:
                printf("Smallest element in the BST: %d\n", smallest(root));
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
