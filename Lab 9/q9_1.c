#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary search tree
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform iterative inorder traversal
void iterativeInorderTraversal(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);

        current = current->right;
    }
}

// Function to find the minimum value node in a BST
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node with the given key from the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to display the menu
void displayMenu() {
    printf("\n1. Insert into BST");
    printf("\n2. Iterative Inorder Traversal");
    printf("\n3. Delete from BST");
    printf("\n4. Exit");
    printf("\nEnter your choice: ");
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("\nIterative Inorder Traversal: ");
                iterativeInorderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("\nEnter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 4:
                printf("\nExiting the program. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}