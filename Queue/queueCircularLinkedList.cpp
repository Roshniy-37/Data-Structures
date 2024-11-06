#include<iostream>
using namespace std;
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T val) {
        data = val;
        next = nullptr;
    }
};
template <typename T>
class CircularQueue {
private:
    Node<T>* front;
    Node<T>* rear;   
public:
    CircularQueue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(T e) {
        Node<T>* n = new Node<T>(e);
        if (isEmpty()) {
            front = n;
            rear = n;
            n->next = n;  
        } else {
            n->next = front;
            rear->next = n;
            rear = n;
        }
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        T value = front->data;
        if (front == rear) {
            delete front;
            front = rear = NULL;  
        } else {
            front = front->next;
            rear->next = front; 
        }
        return value;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node<T>* temp = front;
        cout << "Queue elements: ";
        while (temp->next != front){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << temp->data << " -> ";
        cout << endl;
    }
};

int main() {
    CircularQueue<int> q;
    int choice = 1, value;

    while (choice != 0) {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Check if queue is empty\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to be pushed: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                cout << "Dequeued element: " << q.dequeue() << endl;
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
                break;
            case 0:
                cout << "Exited" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
    return 0;
}
