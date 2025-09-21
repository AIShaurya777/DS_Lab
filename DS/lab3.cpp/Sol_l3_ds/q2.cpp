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

    bool empty() {
        return (top == -1);
    }
};

int main() {
    string str = "DataStructure";
    Stack s;

    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    string rev = "";
    while (!s.empty()) {
        rev += s.pop();
    }

    cout << "Original: " << str << endl;
    cout << "Reversed: " << rev << endl;

    return 0;
}
