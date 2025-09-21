#include <iostream>
using namespace std;

#define SIZE 100  

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return (front > rear);
    }

    bool isFull() {
        return (rear == SIZE - 1);
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        rear++;
        arr[rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int val = arr[front];
        front++;
        return val;
    }

    int size() {
        return (rear - front + 1);
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    int getElement(int i) {
        return arr[front + i];
    }
};


void interleave(Queue &q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue has odd number of elements, cannot interleave.\n";
        return;
    }

    int half = n / 2;
    int firstHalf[50];  
    int secondHalf[50]; 

    for (int i = 0; i < half; i++) {
        firstHalf[i] = q.dequeue();
    }
    for (int i = 0; i < half; i++) {
        secondHalf[i] = q.dequeue();
    }

   
    for (int i = 0; i < half; i++) {
        q.enqueue(firstHalf[i]);
        q.enqueue(secondHalf[i]);
    }
}

int main() {
    Queue q;

    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(11);
    q.enqueue(20);
    q.enqueue(5);
    q.enqueue(9);

    cout << "Original Queue: ";
    q.display();

    interleave(q);

    cout << "Interleaved Queue: ";
    q.display();

    return 0;
}
