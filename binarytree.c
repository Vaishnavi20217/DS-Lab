#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a new node in the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to search for a given value in the BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return search(root->left, data);

    return search(root->right, data);
}

// Function to find the minimum value node in a given tree
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node in the BST (renamed to avoid conflict with the `delete` keyword)
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        printf("Node with value %d not found.\n", data);
        return root;
    }

    // Traverse the tree to find the node to delete
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node to be deleted is found

        // Case 1: Node has no children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Node has only one child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node has two children
        else {
            struct Node* temp = findMin(root->right); // Get the inorder successor
            root->data = temp->data; // Replace root's data with inorder successor's data
            root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
        }
    }
    return root;
}

// In-order Traversal (left, root, right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Pre-order Traversal (root, left, right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order Traversal (left, right, root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Driver program to test the above functions
int main() {
    struct Node* root = NULL;

    // Inserting values into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order traversal: ");
    inorder(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preorder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postorder(root);
    printf("\n");

    // Searching for a value in the BST
    int key = 40;
    struct Node* found = search(root, key);
    if (found != NULL)
        printf("Found %d in the tree.\n", key);
    else
        printf("%d not found in the tree.\n", key);

    // Deleting a node from the BST
    printf("\nDeleting node with value 20...\n");
    root = deleteNode(root, 20);

    printf("In-order traversal after deletion: ");
    inorder(root);
    printf("\n");

    // Deleting a node with two children
    printf("\nDeleting node with value 30...\n");
    root = deleteNode(root, 30);

    printf("In-order traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
