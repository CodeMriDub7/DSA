#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

struct CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    ~CircularLinkedList() {
        if (!head) return;
        Node* curr = head->next;
        while (curr != head) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete head;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = head;
    }

    void insertAtPosition(int data, int position) {
        if (position < 0) return;
        if (position == 0) {
            insertAtBeginning(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* curr = head;
        for (int i = 0; i < position - 1 && curr->next != head; ++i) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void deleteFromBeginning() {
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        Node* temp = head;
        tail->next = head->next;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* curr = head;
        Node* prev = nullptr;
        while (curr->next != head) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = head;
        delete curr;
    }

    void deleteFromPosition(int position) {
        if (!head || position < 0) return;
        if (position == 0) {
            deleteFromBeginning();
            return;
        }
        Node* curr = head;
        Node* prev = nullptr;
        for (int i = 0; i < position && curr->next != head; ++i) {
            prev = curr;
            curr = curr->next;
        }
        if (curr == head) return;
        prev->next = curr->next;
        delete curr;
    }

    void deleteByValue(int key) {
        if (!head) return;
        if (head->data == key) {
            deleteFromBeginning();
            return;
        }
        Node* curr = head->next;
        Node* prev = head;
        while (curr != head) {
            if (curr->data == key) {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void display() {
        if (!head) {
            cout << "Empty List" << endl;
            return;
        }
        Node* curr = head;
        do {
            cout << curr->data << " -> ";
            curr = curr->next;
        } while (curr != head);
        cout << "(HEAD: " << head->data << ")" << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtBeginning(5);
    cll.insertAtPosition(15, 2);
    
    cout << "After Insertions:" << endl;
    cll.display();

    cll.deleteFromBeginning();
    cout << "\nAfter Deleting from Beginning:" << endl;
    cll.display();

    cll.deleteFromEnd();
    cout << "\nAfter Deleting from End:" << endl;
    cll.display();

    cll.insertAtEnd(30);
    cll.insertAtEnd(40);
    cll.deleteFromPosition(1);
    cout << "\nAfter Deleting from Index 1:" << endl;
    cll.display();

    cll.deleteByValue(30);
    cout << "\nAfter Deleting Value 30:" << endl;
    cll.display();

    return 0;
}