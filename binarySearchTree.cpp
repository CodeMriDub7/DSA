#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value) {
    if (!root) {
        Node* node = new Node{value, nullptr, nullptr};
        return node;
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

Node* search(Node* root, int value) {
    if (!root || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

void inorder(Node* root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; ++i) {
        root = insert(root, values[i]);
    }
    inorder(root);
    cout << '\n';
    int key = 60;
    Node* found = search(root, key);
    if (found) {
        cout << "Found " << key << '\n';
    } else {
        cout << "Not found " << key << '\n';
    }
    return 0;
}
