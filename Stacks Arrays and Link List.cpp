#include <iostream>
using namespace std;
 
class Stack {
private:
    int arr[10];
    int top;
 
public:
    Stack() {
        top = -1;
    }
 
    bool isEmpty() {
        return top == -1;
    }
 
    bool isFull() {
        return top == 9;
    }
 
    void push(int val) {
        if (isFull()) {
            cout << "Overflow: Stack is full!" << endl;
            return;
        }
        arr[++top] = val;
    }
 
    int pop() {
        if (isEmpty()) {
            cout << "Underflow: Stack is empty!" << endl;
            return -1;
        }
        return arr[top--];
    }
 
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }
 
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};



struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
 
class LinkedStack {
private:
    Node* top;
 
public:
    LinkedStack() {
        top = NULL;
    }
 
    bool isEmpty() {
        return top == NULL;
    }
 
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }
 
    int pop() {
        if (isEmpty()) {
            cout << "Underflow: Stack is empty!" << endl;
            return -1;
        }
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
 
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }
 
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack (top to bottom): ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


int main() {
    // --- Array Stack demo ---
    Stack s1;
    cout << "=== Array Stack ===" << endl;
    s1.push(10); s1.push(20); s1.push(30);
    s1.push(40); s1.push(50);
    s1.display();
    s1.pop(); s1.pop();
    cout << "After 2 pops: "; s1.display();
    cout << "Peek: " << s1.peek() << endl;
 
    Stack emptyS;
    emptyS.pop();   // underflow test
 
    // --- Linked List Stack demo ---
    LinkedStack s2;
    cout << "\n=== Linked Stack ===" << endl;
    s2.push(1); s2.push(2); s2.push(3);
    s2.push(4); s2.push(5);
    s2.display();
    s2.pop(); s2.pop();
    cout << "After 2 pops: "; s2.display();
    cout << "Peek: " << s2.peek() << endl;
 
    LinkedStack emptyL;
    emptyL.pop();   // underflow test
 
    return 0;
}

