#include <iostream>
using namespace std;
 
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
 
class Queue {
private:
    Node* front;
    Node* rear;
 
public:
    Queue() {
        front = NULL;
        rear  = NULL;
    }
 
    // Destructor frees all nodes
    ~Queue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
 
    bool isEmpty() {
        return front == NULL;
    }
 
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == NULL) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
 
    int dequeue() {
        if (isEmpty()) {
            cout << "Underflow: Queue is empty!" << endl;
            return -1;
        }
        int val = front->data;
        Node* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
        return val;
    }
 
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }
 
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue (front to rear): ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
class CircularQueue {
private:
    int arr[6];
    int front, rear, count;
 
public:
    CircularQueue() {
        front = 0;
        rear  = 0;
        count = 0;
    }
 
    bool isEmpty() { return count == 0; }
    bool isFull()  { return count == 6; }
 
    void enqueue(int val) {
        if (isFull()) {
            cout << "Overflow: Circular Queue is full!" << endl;
            return;
        }
        arr[rear] = val;
        rear = (rear + 1) % 6;   // wrap using modulo
        count++;
    }
 
    int dequeue() {
        if (isEmpty()) {
            cout << "Underflow: Circular Queue is empty!" << endl;
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % 6; // wrap using modulo
        count--;
        return val;
    }
 
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Circular Queue: ";
        int i = front;
        for (int k = 0; k < count; k++) {
            cout << arr[i] << " ";
            i = (i + 1) % 6;
        }
        cout << endl;
    }
};
int main() {
    // Linked list queue
    Queue q;
    cout << "=== Linked List Queue ===" << endl;
    q.enqueue(10); q.enqueue(20); q.enqueue(30);
    q.enqueue(40); q.enqueue(50);
    q.display();
    q.dequeue(); q.dequeue();
    cout << "After 2 dequeues: "; q.display();
    cout << "Front: " << q.getFront() << endl;
 
    // Circular queue
    CircularQueue cq;
    cout << "\n=== Circular Queue ===" << endl;
    cq.enqueue(1); cq.enqueue(2); cq.enqueue(3);
    cq.enqueue(4); cq.enqueue(5); cq.enqueue(6);
    cq.display();
    cq.enqueue(7);          // overflow test
    cq.dequeue(); cq.dequeue();
    cq.enqueue(7); cq.enqueue(8); // wrap-around demo
    cq.display();
 
    return 0;
}

