#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node* prev;
};
node* head = nullptr;
void insertAtEnd(int value){
    node* newNode = new node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if(head == nullptr){
        head = newNode;
    }
    else{
        node* temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void insertAtBeginning(int value){
    node* newNode = new node;
    newNode->data = value;
    newNode->next = head;
    newNode->prev = nullptr;
    if(head != nullptr){
        head->prev = newNode;
    }
    head = newNode;
}
void insertAtPosition(int value, int position){
    node* newNode = new node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if(position == 1){
        newNode->next = head;
        if(head != nullptr){
            head->prev = newNode;
        }
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
    newNode->prev = temp;
    if(temp->next != nullptr){
        temp->next->prev = newNode;
    }
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
        if(head != nullptr){
            head->prev = nullptr;
        }
        delete temp;
        return;
    }
    for(int i = 1; i < position && temp != nullptr; i++){
        temp = temp->next;
    }
    if(temp == nullptr){
        cout << "Position out of bounds" << endl;
        return;
    }
    temp->prev->next = temp->next;
    if(temp->next != nullptr){
        temp->next->prev = temp->prev;
    }
    delete temp;
}
void deleteLast(){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }
    node* temp = head;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    if(temp->prev != nullptr){
        temp->prev->next = nullptr;
    }
    else{
        head = nullptr;
    }
    delete temp;
}
void deleteFirst(){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }
    node* temp = head;
    head = head->next;
    if(head != nullptr){
        head->prev = nullptr;
    }
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
    insertAtBeginning(5);
    insertAtPosition(15, 3);
    cout << "List after insertions: ";
    display();
    deleteAtPosition(3);
    cout << "List after deleting position 3: ";
    display();
    deleteLast();
    cout << "List after deleting last element: ";
    display();
    deleteFirst();
    cout << "List after deleting first element: ";
    display();
    return 0;
}