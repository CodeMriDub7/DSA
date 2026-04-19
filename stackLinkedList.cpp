#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* top = nullptr;
void push(int value){
    node* newNode = new node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}
void pop(){
    if(top == nullptr){
        cout << "Stack underflow" << endl;
        return;
    }
    node* temp = top;
    top = top->next;
    delete temp;
}
void display(){
    node* temp = top;
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    display();
    push(30);
    push(40);
    display();
    push(10);
    push(20);
    display();
    pop();
    display();    
    pop();
    display();
    return 0;
}