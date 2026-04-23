#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insertEmpty(Node* last, int data) {
    if (last != NULL) return last;
    Node* newNode = new Node;
    newNode->data = data;
    last = newNode;
    last->next = last;
    return last;
}

Node* insertBegin(Node* last, int data) {
    if (last == NULL) return insertEmpty(last, data);
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
    return last;
}

Node* insertEnd(Node* last, int data) {
    if (last == NULL) return insertEmpty(last, data);
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
    return last;
}

Node* insertAfter(Node* last, int data, int item) {
    if (last == NULL) return NULL;
    Node *newNode, *p;
    p = last->next;
    do {
        if (p->data == item) {
            newNode = new Node;
            newNode->data = data;
            newNode->next = p->next;
            p->next = newNode;
            if (p == last) last = newNode;
            return last;
        }
        p = p->next;
    } while (p != last->next);
    return last;
}

Node* deleteNode(Node* last, int key) {
    if (last == NULL) return NULL;
    if (last->data == key && last->next == last) {
        delete last;
        return NULL;
    }
    Node *temp = last, *d;
    if (last->next->data == key) {
        d = last->next;
        last->next = d->next;
        delete d;
        return last;
    }
    while (temp->next != last && temp->next->data != key) {
        temp = temp->next;
    }
    if (temp->next->data == key) {
        d = temp->next;
        temp->next = d->next;
        if (d == last) last = temp;
        delete d;
    }
    return last;
}

void display(Node* last) {
    if (last == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* p = last->next;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != last->next);
    cout << endl;
}

int main() {
    Node* last = NULL;
    last = insertEmpty(last, 10);
    last = insertBegin(last, 5);
    last = insertEnd(last, 20);
    last = insertAfter(last, 15, 10);
    display(last);
    last = deleteNode(last, 5);
    last = deleteNode(last, 20);
    display(last);
    return 0;
}
