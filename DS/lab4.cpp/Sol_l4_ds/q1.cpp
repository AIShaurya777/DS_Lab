#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == SIZE - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full, cannot insert.\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        arr[rear] = value;
        cout << value << " added to the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, nothing to remove.\n";
            return;
        }
        cout << arr[front] << " removed from the queue.\n";
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Front element is: " << arr[front] << "\n";
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            if (q.isEmpty())
                cout << "Queue is empty.\n";
            else
                cout << "Queue is not empty.\n";
            break;
        case 6:
            if (q.isFull())
                cout << "Queue is full.\n";
            else
                cout << "Queue is not full.\n";
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, try again.\n";
        }
    } while (choice != 7);

    return 0;
}
