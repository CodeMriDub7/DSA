#include <iostream>
using namespace std; 
const int MAX = 5; 

void enqueue(int circularQueue[], int &front, int &rear, int value){
    if((rear + 1) % MAX == front){
        cout << "Queue overflow" << endl;
        return;
    }
    if(front == -1) front = 0;
    rear = (rear + 1) % MAX;
    circularQueue[rear] = value;
}
void dequeue(int circularQueue[], int &front, int &rear){
    if(front == -1){
        cout << "Queue underflow" << endl;
        return;
    }
    if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front + 1) % MAX;
    }
}
void display(int circularQueue[], int front, int rear){
    if(front == -1){
        cout << "Queue is empty" << endl;
        return;
    }
    int i = front;
    while(i != rear){
        cout << circularQueue[i] << " ";
        i = (i + 1) % MAX;
    }
    cout << circularQueue[rear] << endl;
}

int main(){
    int circularQueue[MAX];
    int front = -1, rear = -1;
    enqueue(circularQueue, front, rear, 10);
    enqueue(circularQueue, front, rear, 20);
    display(circularQueue, front, rear);
    enqueue(circularQueue, front, rear, 30);
    dequeue(circularQueue, front, rear);
    display(circularQueue, front, rear);
    enqueue(circularQueue, front, rear, 40);
    enqueue(circularQueue, front, rear, 50);
    display(circularQueue, front, rear);
    dequeue(circularQueue, front, rear);
    display(circularQueue, front, rear);
    return 0;
}