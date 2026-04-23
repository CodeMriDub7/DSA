#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};

int height(Node* node) {
    if (!node) {
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

Node* createNode(int value) {
    Node* node = new Node;
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;
    x->right = y;
    y->left = t2;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;
    y->left = x;
    x->right = t2;
    return y;
}

int getBalance(Node* node) {
    if (!node) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

Node* insert(Node* root, int value) {
    if (!root) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        return root;
    }
    int balance = getBalance(root);
    if (balance > 1 && value < root->left->data) {
        return rightRotate(root);
    }
    if (balance < -1 && value > root->right->data) {
        return leftRotate(root);
    }
    if (balance > 1 && value > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

Node* search(Node* root, int value) {
    if (!root || root->data == value) {
        if (root) {
            cout << "Given node is found!!!" << '\n';
        } else {
            cout << "Element is not found" << '\n';
        }
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int value) {
    if (!root) {
        return root;
    }
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    if (!root) {
        return root;
    }
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inorder(Node* root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void display(Node* root) {
    inorder(root);
    cout << '\n';
}

int main() {
    Node* root = nullptr;
    int values[] = {30, 20, 40, 10, 25, 35, 50, 5, 15};
    for (int i = 0; i < 9; ++i) {
        root = insert(root, values[i]);
    }
    display(root);
    search(root, 25);
    search(root, 100);
    root = deleteNode(root, 20);
    display(root);
    return 0;
}

