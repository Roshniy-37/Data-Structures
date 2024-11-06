#include <iostream>
using namespace std;
template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T value) {
        data = value;
        next = nullptr;
    }
};
template <typename T>
class Stack {
private:
    Node<T>* top;
public:
    Stack() {
        top = nullptr;
    }
    void push(T element) {
        Node<T>* newNode = new Node<T>(element);
        newNode->next = top;
        top = newNode;
    }
    T pop(){
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return T(); 
        }
        T value = top->data;
        Node<T>* temp = top;
        top = top->next;
        delete temp;
        return value;
    }
    T peek() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return T();  
        }
        return top->data;
    }
    bool isFull() {
        return false; 
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return;
        }
        cout << "Stack elements: ";
        Node<T>* current = top;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack<int> s;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Stack is Empty\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to be push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                cout << "Popped element: " << s.pop() << endl;
                break;
            case 3:
                cout << "Peek element: " << s.peek() << endl;
                break;
            case 4:
                s.display();
                break;
            case 5:
                cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
                break;
            case 0:
                cout << "Exited" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    } while (choice != 0);
    return 0;
}
