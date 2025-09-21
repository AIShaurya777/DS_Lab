#include <iostream>
using namespace std;

#define SIZE 5

class Stack {
    int arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == SIZE - 1);
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack is full! Cannot push " << x << endl;
        } else {
            arr[++top] = x;
            cout << x << " pushed to stack." << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Pop is not possible." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot display." << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty! Nothing to peek." << endl;
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }
};

int main() {
    Stack S;
    int choice, value;

    do {
        cout << "\n--- STACK MENU ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Peek" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                S.push(value);
                break;
            case 2:
                S.pop();
                break;
            case 3:
                S.display();
                break;
            case 4:
                S.peek();
                break;
            case 5:
                if(S.isEmpty())
                    cout << "Stack is empty." << endl;
                else
                    cout << "Stack is not empty." << endl;
                break;
            case 6:
                if(S.isFull())
                    cout << "Stack is full." << endl;
                else
                    cout << "Stack is not full." << endl;
                break;
            case 7:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);

    return 0;
}

