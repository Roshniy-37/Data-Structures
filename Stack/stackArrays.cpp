#include <iostream>
using namespace std;
template <typename T>
class Stack {
    private:
        int top;
        int capacity;
        T* stackArray;
    public:
        Stack(int size) {
            capacity = size;
            stackArray = new T[capacity];
            top = -1;
        }
        void push(T element) {
            if (isFull()) {
                cout << "Stack overflow" << endl;
                return;
            }
            top+=1;
            stackArray[top] = element;
        }
        T pop() {
            if (isEmpty()) {
                cout << "Stack underflow" << endl;
                return -1; 
            }
            T temp = stackArray[top];
            top--;
            return temp;
        }
        T peek() {
            if (isEmpty()) {
                cout << "Stack underflow" << endl;
                return -1; 
            }
            return stackArray[top];
        }
        bool isFull() {
            return top == capacity - 1;
        }
        bool isEmpty() {
            return top == -1;
        }
        void display() {
            if (isEmpty()) {
                cout << "Underflow" << endl;
                return;
            }
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << stackArray[i] << ", ";
            }
            cout << endl;
        }
};
int main() {
    Stack<char> s(100); 
    int choice = 1, value;

   while (choice != 0){
        cout << "\nMenu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Stack is Full\n";
        cout << "6. Check if Stack is Empty\n";
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
                cout << "Is stack full? " << (s.isFull() ? "Yes" : "No") << endl;
                break;
            case 6:
                cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
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
