#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};
node* front = nullptr;
node* rear = nullptr;
void enqueue(int value){
    node* newNode = new node;
    newNode->data = value;
    newNode->next = nullptr;
    if(rear == nullptr){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
}
void dequeue(){
    if(front == nullptr){
        cout << "Queue underflow" << endl;
        return;
    }
    node* temp = front;
    front = front->next;
    if(front == nullptr){
        rear = nullptr;
    }
    delete temp;
}
void display(){
    node* temp = front;
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    display();
    enqueue(10);
    display();
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    dequeue();
    display();
    return 0;
}