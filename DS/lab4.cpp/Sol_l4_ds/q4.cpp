#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 100


class Queue {
    char arr[SIZE];
    int front, rear;
public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    void enqueue(char x) {
        if (rear < SIZE - 1) {
            rear++;
            arr[rear] = x;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            front++;
        }
    }

    char peek() {
        if (!isEmpty())
            return arr[front];
        return '\0';
    }
};

int main() {
    char str[SIZE];
    cout << "Enter string: ";
    cin.getline(str, SIZE);

    int freq[256] = {0}; 
    Queue q;

    cout << "Output: ";
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == ' ') continue; 
       
        freq[(int)ch]++;

       
        q.enqueue(ch);

       
        while (!q.isEmpty() && freq[(int)q.peek()] > 1) {
            q.dequeue();
        }

       
        if (q.isEmpty()) {
            cout << "-1 ";
        } else {
            cout << q.peek() << " ";
        }
    }
    cout << "\n";

    return 0;
}
