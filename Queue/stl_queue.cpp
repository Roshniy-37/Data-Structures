#include<iostream>
#include<queue>
using namespace std;
void display(queue<int> s){
     if (s.empty()) {
        cout << "Underflow" << endl;
        return;
    }
    cout << "Queue elements: ";
    while (!s.empty()) {
        int n = s.front();
        s.pop();
        cout << n << " ";
    }
    cout << endl;
}
int main(){
    queue<int> q;
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
                q.push(value);
                break;
            case 2:
                cout << "Dequeued element: " << q.front() << endl;
                q.pop();
                break;
            case 3:
                display(q);
                break;
            case 4:
                cout << "Is queue empty? " << (q.size() ? "Yes" : "No") << endl;
                break;
            case 0:
                cout << "Exited" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
}