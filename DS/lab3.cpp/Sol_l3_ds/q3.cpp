#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char x) {
        if (top == MAX - 1)
            cout << "Overflow\n";
        else
            arr[++top] = x;
    }

    char pop() {
        if (top == -1) {
            return '\0';
        } else {
            return arr[top--];
        }
    }

    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }

    bool empty() {
        return (top == -1);
    }
};

bool match(char a, char b) {
    return (a == '(' && b == ')') ||(a == '{' && b == '}') ||(a == '[' && b == ']');
}

bool balanced(string exp) {
    Stack s;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) 
            return false;
            char top = s.pop();
            if (!match(top, ch))
             return false;
        }
    }

    return s.empty();
}

int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;

    if (balanced(exp))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}
