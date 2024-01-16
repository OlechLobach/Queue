#include"queue.h"

int main() {
    PriorityQueue<int> priorityQueue;

    int value, priority, choice;

    do {
        cout << "1. Insert element with priority\n"
            "2. Pull highest priority element\n"
            "3. Peek\n"
            "4. Show\n"
            "0. Exit\n"
            "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter priority: ";
            cin >> priority;
            priorityQueue.InsertWithPriority(value, priority);
            break;
        case 2:
            priorityQueue.PullHighestPriorityElement();
            cout << "Pulled the highest priority element." << endl;
            break;
        case 3:
            try {
                cout << "Peek: " << priorityQueue.Peek() << endl;
            }
            catch (const out_of_range& e) {
                cout << e.what() << endl;
            }
            break;
        case 4:
            cout << "Current queue:" << endl;
            priorityQueue.Show();
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 0);

    return 0;
}