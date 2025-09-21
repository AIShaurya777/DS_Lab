#include <iostream>
#include <cmath>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
        } else {
            arr[++top] = x;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        } else {
            return arr[top--];
        }
    }

    bool empty() {
        return (top == -1);
    }
};

int evaluate(string exp) {
    Stack s;

   
    return s.pop();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    int ans = evaluate(postfix);
    cout << "Result: " << ans << endl;

    return 0;
}
