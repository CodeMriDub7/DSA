#include <iostream>
using namespace std; 
struct Node {
    int data;
    Node* next;
};
Node* rear = nullptr;
bool isEmpty() {
    return rear == nullptr;
}
void enqueue(int value) {
    Node* newNode = new Node{value, nullptr};
    if (isEmpty()) {
        newNode->next = newNode;
        rear = newNode;
    } else {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Enqueued: " << value << '\n';
}
int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << '\n';
        return -1;
    }
    Node* front = rear->next;
    int value = front->data;
    if (front == rear) {
        delete front;
        rear = nullptr;
    } else {
        rear->next = front->next;
        delete front;
    }
    cout << "Dequeued: " << value << '\n';
    return value;
}
void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << '\n';
        return;
    }
    Node* current = rear->next;
    cout << "Circular Queue: ";
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != rear->next);
    cout << '\n';
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    dequeue();
    dequeue();
    dequeue();
    return 0;
}
