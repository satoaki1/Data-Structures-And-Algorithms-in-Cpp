//
// Created by Satoaki Ishihara on 2023/09/08.
//

#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node *newNode(int data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

// Function to insert a node in Binary Search Tree
struct node *insert(struct node *node, int data) {
    // Return a new node if the tree is empty
    if (node == NULL) return newNode(data);

    // Traverse to the right place and insert the node
    if (data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);

    return node;
}

// Method to print the tree in inorder manner.
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Traverse Preorder
void preorder(struct node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Traverse Postorder
void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Driver code
int main() {
    struct node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    cout << "Inorder traversal: ";
    inorder(root);

    cout << "\nPreorder traversal: ";
    preorder(root);

    cout << "\nPostorder traversal: ";
    postorder(root);

    cout << endl;

    return 0;
}