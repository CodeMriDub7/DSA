#include <iostream>

using namespace std;

struct Item {
    int value;
    int priority;
};

Item pq[100];
int size = 0;

void enqueue(int val, int p) {
    pq[size].value = val;
    pq[size].priority = p;
    size++;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (pq[j].priority > pq[j + 1].priority) {
                Item temp = pq[j];
                pq[j] = pq[j + 1];
                pq[j + 1] = temp;
            }
        }
    }
}

int peek() {
    return pq[0].value;
}

void dequeue() {
    for (int i = 0; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

int main() {
    enqueue(10, 2);
    enqueue(20, 1);
    enqueue(30, 3);

    cout << "Highest priority element: " << peek() << endl;

    dequeue();
    cout << "Next highest priority element: " << peek() << endl;

    return 0;
}
