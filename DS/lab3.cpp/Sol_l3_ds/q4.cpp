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
            cout << "Underflow\n";
            return 0;
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

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

string infixToPostfix(string infix) {
    Stack s;
    string post = "";

    for (int i = 0; i < infix.length(); i++) {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            post += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.peek() != '(') {
                post += s.pop();
            }
            s.pop();
        }
        else {
            while (!s.empty() && prec(s.peek()) >= prec(ch)) {
                post += s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        post += s.pop();
    }

    return post;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    return 0;
}
