#include <iostream>
using namespace std;
const int SIZE = 10;

void push(int stack[], int& top, int value){
    if(top >= SIZE - 1){
        cout << "Stack overflow" << endl;
        return;
    }
    stack[++top] = value;
}

void pop(int stack[], int& top){
    if(top < 0){
        cout << "Stack underflow" << endl;
        return;
    }
    top--;
}
void display(int stack[], int top){
    for(int i = top; i >= 0; i--){
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main(){
    int stack[SIZE];
    int top = -1;
    display(stack, top);
    push(stack, top, 30);
    push(stack, top, 40);
    display(stack, top);
    push(stack, top, 10);
    push(stack, top, 20);
    display(stack, top);
    pop(stack, top);
    display(stack, top);    
    pop(stack, top);
    display(stack, top);
    return 0;
}