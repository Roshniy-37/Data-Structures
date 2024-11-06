#include <iostream>
using namespace std;
class Node {
public:
    int element;
    Node* next;
    Node(int e) {
        element = e;
        next = nullptr;
    }
};
class CircularLinkedList {
public:
    Node* head;
    Node* tail;
    CircularLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    void AddAtBeginning(int e) {
        Node* n = new Node(e);
        if (head == nullptr) {
            head = tail = n;
            head->next = head;
        } else {
            n->next = head;
            tail->next = n;
            head = n;
        }
    }
    void AddAtEnd(int e) {
        Node* n = new Node(e);
        if (head == nullptr) {
            head = tail = n;
            head->next = head;
        } else {
            tail->next = n;
            n->next = head;
            tail = n;
        }
    }
    void RemoveAtBeginning() {
        if (head == nullptr) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }
    void RemoveAtEnd() {
        if (head == nullptr) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = head;
            delete tail;
            tail = temp;
        }
    }
    void display() {
        if (head == nullptr) {
            cout << "Empty" << endl;
            return;
        }
        Node* temp = head;
        cout<< head->element<<" -> ";
        temp = head->next;
        while (temp != head){
            cout << temp->element << " -> ";
            temp = temp->next;
        } 
        cout << endl;
    }
    int searchElement(int e) {
        if (head == nullptr) return 0;
        Node* temp = head;
        int pos = 1;
        while (temp != head){
            if (temp->element == e) return pos;
            temp = temp->next;
            pos++;
        } 
        return 0;
    }

    void addAtPosition(int e, int pos) {
        if (pos == 1 || head==nullptr) {
            AddAtBeginning(e);
            return;
        }
        Node* n = new Node(e);
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        if (temp == tail) {
            AddAtEnd(e);
        } else {
            n->next = temp->next;
            temp->next = n;
        }
    }
    void removeAtPosition(int pos) {
        if (head == nullptr) return;
        if (pos == 1) {
            RemoveAtBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        if (temp->next == tail) {
            RemoveAtEnd();
        } else {
            Node* x = temp->next;
            temp->next = x->next;
            delete x;
        }
    }
    void reverse() {
        if (head == nullptr || head == tail) return;
        Node* prev = nullptr; 
        Node* current = head;
        Node* next = nullptr;
        while (current->next != head){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        tail = head;
        tail->next = prev;  
        head = prev;
    }
};
int main() {
    CircularLinkedList list;
     int choice = 1, element, position;
    while (choice != 0){
        cout << "\nMenu:\n";
        cout << "1. Add at Beginning\n";
        cout << "2. Add at End\n";
        cout << "3. Remove from Beginning\n";
        cout << "4. Remove from End\n";
        cout << "5. Display List\n";
        cout << "6. Search for Element\n";
        cout << "7. Add at Position\n";
        cout << "8. Remove at Position\n";
        cout << "9. Reverse List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter element to add at beginning: ";
                cin >> element;
                list.AddAtBeginning(element);
                break;

            case 2:
                cout << "Enter element to add at end: ";
                cin >> element;
                list.AddAtEnd(element);
                break;

            case 3:
                list.RemoveAtBeginning();
                break;

            case 4:
                list.RemoveAtEnd();
                break;

            case 5:
                list.display();
                break;

            case 6:
                cout << "Enter element to search: ";
                cin >> element;
                position = list.searchElement(element);
                if (position)
                    cout << "Element found at position " << position << endl;
                else
                    cout << "Element not found" << endl;
                break;

            case 7:
                cout << "Enter element to add: ";
                cin >> element;
                cout << "Enter position: ";
                cin >> position;
                list.addAtPosition(element, position);
                break;

            case 8:
                cout << "Enter position to remove: ";
                cin >> position;
                list.removeAtPosition(position);
                break;

            case 9:
                list.reverse();
                break;

            case 0:
                cout << "Exited" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    } 
    return 0;
}
