#include<iostream>
#include<deque>
using namespace std;
void display(deque<int> s){
     if (s.empty()) {
        cout << "Underflow" << endl;
        return;
    }
    cout << "Queue elements: ";
    while (!s.empty()) {
        int n = s.front();
        s.pop_front();
        cout << n << " ";
    }
    cout << endl;
}
int main(){
    deque<int> q;
    int choice = 1, value;

    while (choice != 0){
        cout << "\nMenu:\n";
        cout << "1. Enqueue at Front\n";
        cout << "2. Enqueue at Back\n";
        cout << "3. Dequeue at Front\n";
        cout << "4. Dequeue at Back\n";
        cout << "5. Display\n";
        cout << "6. Check if dequeue is Empty\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue at front: ";
                cin >> value;
                q.push_front(value);
                break;
            case 2:
                cout << "Enter the value to enqueue at back: ";
                cin >> value;
                q.push_back(value);
                break;
            case 3:
                cout << "Dequeued element from front: " << q.front() << endl;
                q.pop_front();
                break;
            case 4:
                cout << "Dequeued element from back: " << q.back() << endl;
                q.pop_back();
                break;
            case 5:
                display(q);
                break;
            case 6:
                cout << "Is dequeue empty? " << (q.empty() ? "Yes" : "No") << endl;
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