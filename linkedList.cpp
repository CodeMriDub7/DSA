#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
};

node* head = NULL;

void insertAtEnd(int value){
    node* newNode = new node;
    newNode->data = value;
    newNode->next = nullptr;
    if(head == nullptr){
        head = newNode;
    }
    else{
        node* temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtBeginning(int value){
    node* newNode = new node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtPosition(int value, int position){
    node* newNode = new node;
    newNode->data = value;
    newNode->next = nullptr;
    if(position == 1){
        newNode->next = head;
        head = newNode;
        return;
    }
    node* temp = head;
    for(int i = 1; i < position - 1 && temp != nullptr; i++){
        temp = temp->next;
    }
    if(temp == nullptr){
        cout << "Position out of bounds" << endl;
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtPosition(int position){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }
    node* temp = head;
    if(position == 1){
        head = temp->next;
        delete temp;
        return;
    }
    for(int i = 1; i < position - 1 && temp != nullptr; i++){
        temp = temp->next;
    }
    if(temp == nullptr || temp->next == nullptr){
        cout << "Position out of bounds" << endl;
        return;
    }
    node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}
void deleteAtEnd(){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }
    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }
    node* temp = head;
    while (temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}
void deleteAtBeginning(){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
}

void display(){
    node* temp = head;
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    display();
    insertAtBeginning(5);
    display();
    insertAtPosition(15, 3);
    display();
    deleteAtPosition(2);
    display();
    deleteAtEnd();
    display();
    deleteAtBeginning();
    display();
    return 0;
}