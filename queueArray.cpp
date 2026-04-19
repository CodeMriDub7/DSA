#include <iostream>
using namespace std;
const int SIZE = 10;

void enqueue(int queue[], int& front, int& rear, int value){
    if((rear + 1) % SIZE == front){
        cout << "Queue overflow" << endl;
        return;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    if(front == -1){
        front = rear;
    }
}
void dequeue(int queue[], int& front, int& rear){
    if(front == -1){
        cout << "Queue underflow" << endl;
        return;
    }
    if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front + 1) % SIZE;
    }
}
void display(int queue[], int front, int rear){
    if(front == -1){
        cout << "Queue is empty" << endl;
        return;
    }
    int i = front;
    while (true){
        cout << queue[i] << " ";
        if(i == rear){
            break;
        }
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main(){
    int queue[SIZE];
    int front = -1, rear = -1;
    // Enqueue elements
    enqueue(queue, front, rear, 10);
    display(queue, front, rear);
    enqueue(queue, front, rear, 20);
    enqueue(queue, front, rear, 30);
    display(queue, front, rear);
    // Dequeue elements
    dequeue(queue, front, rear);
    display(queue, front, rear);
    dequeue(queue, front, rear);
    display(queue, front, rear);
    return 0;
}