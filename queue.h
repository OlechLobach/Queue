#include <iostream>
#include<queue>
using namespace std;


template <typename T>
class PriorityQueue {
private:
    struct QueueNode {
        T data;
        int priority;
        QueueNode* next;

        QueueNode(const T& value, int p) : data(value), priority(p), next(nullptr) {}
    };

    QueueNode* front;

public:
   
    PriorityQueue() : front(nullptr) {}

    
    bool IsEmpty() const {
        return front == nullptr;
    }

    
    void InsertWithPriority(const T& value, int priority) {
        QueueNode* newNode = new QueueNode(value, priority);

        if (IsEmpty() || priority > front->priority) {
            newNode->next = front;
            front = newNode;
        }
        else {
            QueueNode* current = front;

            while (current->next != nullptr && priority <= current->next->priority) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }

    
    void PullHighestPriorityElement() {
        if (!IsEmpty()) {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
        else {
            cout << "Queue is empty. Cannot pull element." << endl;
        }
    }


    T Peek() const {
        if (!IsEmpty()) {
            return front->data;
        }
        else {
            throw out_of_range("Queue is empty. Cannot peek.");
        }
    }


    void Show() const {
        if (IsEmpty()) {
            cout << "Queue is empty." << endl;
        }
        else {
            QueueNode* current = front;
            while (current != nullptr) {
                cout << "Value: " << current->data << ", Priority: " << current->priority << endl;
                current = current->next;
            }
        }
    }
};