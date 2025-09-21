#include<iostream>
using namespace std;

class Q{
    int size;
    int *arr;
    int rear;
    int front;
public:
    Q(){
        size=1000;
        arr=new int[size];
        front=0;
        rear=0;
    }
    void enqueue(int x){
        if(rear==size) return;
        arr[rear]=x;
        rear=rear+1;
    }
    void dequeue(){
        if(front==rear) return;
        front=front+1;
        if(front==rear) front=rear=0;
    }
    int peek(){
        if(front==rear) return -1;
        return arr[front];
    }
    bool isEmpty(){
        return front==rear;
    }
    int getSize(){
        return rear-front;
    }
};

// ---------- Stack using Two Queues ----------
class StackTwoQ{
    Q q1,q2;
public:
    void push(int x){
        q1.enqueue(x);
    }
    void pop(){
        if(q1.isEmpty()){
            cout<<"Stack empty\n";
            return;
        }
        int n=q1.getSize();
        for(int i=0;i<n-1;i++){
            q2.enqueue(q1.peek());
            q1.dequeue();
        }
        cout<<"Popped: "<<q1.peek()<<endl;
        q1.dequeue();
        swap(q1,q2);
    }
    int top(){
        if(q1.isEmpty()) return -1;
        int n=q1.getSize();
        for(int i=0;i<n-1;i++){
            q2.enqueue(q1.peek());
            q1.dequeue();
        }
        int res=q1.peek();
        q2.enqueue(res);
        q1.dequeue();
        swap(q1,q2);
        return res;
    }
};

// ---------- Stack using One Queue ----------
class StackOne{
    Q q;
public:
    void push(int x){
        int n=q.getSize();
        q.enqueue(x);
        for(int i=0;i<n;i++){
            int val=q.peek();
            q.enqueue(val);
            q.dequeue();
        }
    }
    void pop(){
        if(q.isEmpty()){
            cout<<"Stack empty\n";
            return;
        }
        cout<<"Popped: "<<q.peek()<<endl;
        q.dequeue();
    }
    int top(){
        if(q.isEmpty()) return -1;
        return q.peek();
    }
};

int main(){
    cout<<"--- Stack using Two Queues ---\n";
    StackTwoQ st1;
    st1.push(10);
    st1.push(20);
    st1.push(30);
    cout<<"Top: "<<st1.top()<<endl;
    st1.pop();
    cout<<"Top: "<<st1.top()<<endl;

    cout<<"\n--- Stack using One Queue ---\n";
    StackOne st2;
    st2.push(5);
    st2.push(10);
    st2.push(15);
    cout<<"Top: "<<st2.top()<<endl;
    st2.pop();
    cout<<"Top: "<<st2.top()<<endl;
}
