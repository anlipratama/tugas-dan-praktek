#include <bits/stdc++.h>
using namespace std;

// Struktur Node Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Membuat node baru
Node* newNode(int x) {
    Node* n = new Node;
    n->data = x;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Traversal Inorder (Left - Root - Right)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Traversal Preorder (Root - Left - Right)
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Traversal Postorder (Left - Right - Root)
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    // Membuat tree
    Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);

    // Menampilkan traversal
    cout << "Inorder   : ";
    inorder(root);

    cout << "\nPreorder  : ";
    preorder(root);

    cout << "\nPostorder : ";
    postorder(root);

    return 0;
}

