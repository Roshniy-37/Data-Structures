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
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;
public:
    Queue() {
        front = rear = NULL;
    }
    bool isEmpty() {
        return front == NULL;
    }
    void enqueue(T e){
        Node<T>* n = new Node<T>(e);
        if (isEmpty()) {
            front = rear = n;
        }else{
            rear->next = n;
            rear = n;
        }
    }
    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }else{
            Node<T>* temp = front;
            T val = temp->data;
            front = front->next;
            delete temp;
            return val;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node<T>* temp = front;
        cout << "Queue elements: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue<int> q; 
    int choice = 1, value;

    while (choice != 0){
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
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
