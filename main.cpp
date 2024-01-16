
#include"queue.h"
int main() {
    Queue<int> intQueue;

    int choice;

    do {
        cout << "1. Enqueue  2. Dequeue  3. Show  4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            int value;
            cout << "Enter value to enqueue: ";
            cin >> value;
            intQueue.Enqueue(value);
            break;

        case 2:
            intQueue.Dequeue();
            cout << "Dequeue operation performed." << endl;
            break;

        case 3:
            cout << "Queue contents: ";
            intQueue.Show();
            break;

        case 4:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}