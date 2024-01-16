#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include<queue>
using namespace std;
template <typename T>
class Queue {
private:
    static const int MAX_SIZE = 100; 
    T elements[MAX_SIZE];
    int front; 
    int rear;  

public:
    Queue() : front(-1), rear(-1) {}

   
    bool IsEmpty() const {
        return front == -1;
    }

    
    bool IsFull() const {
        return (rear + 1) % MAX_SIZE == front;
    }

    
    void Enqueue(const T& value) {
        if (IsFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (IsEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % MAX_SIZE;
        }

        elements[rear] = value;
    }

    
    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        if (front == rear) {
           
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX_SIZE;
        }
    }

   
    void Show() const {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        int current = front;
        while (current != rear) {
            cout << elements[current] << " ";
            current = (current + 1) % MAX_SIZE;
        }
        cout << elements[rear] << endl;
    }
};
#endif