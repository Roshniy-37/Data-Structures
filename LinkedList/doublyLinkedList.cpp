#include <iostream>
using namespace std;
class Node{
    public:
        int element;
        Node* prev;
        Node* next;
        Node(){
            element = 0;
            prev = nullptr;
            next = nullptr;
        }
        Node(int e){
        element = e;
        prev = nullptr;
        next = nullptr;
        }
};
class DoublyLinkedList {
    public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
        }
    int AddAtBeginning(int e){
        Node* n = new Node(e);
        if (head == nullptr) {   
                head = tail = n;     
            } else {
                n->next = head;      
                head->prev = n;      
                head = n;          
            }
            return 0; 
    }
    int AddAtEnd(int e){
        Node* n = new Node(e);
        if (head == nullptr) {   
                head = tail = n;     
            } else {
                tail->next = n;      
                n->prev = tail;
                tail = n; 
                tail->next = nullptr;              
            }
            return 0; 
    }
    void RemoveAtBeginning(){
        if(head==nullptr){
            return;
        }else{
            head=head->next;
            delete head->prev;
            head->prev=nullptr;
        }
    }
    void RemoveAtEnd(){
        if(head==nullptr){
            return;
        }else{
            tail=tail->prev;
            delete tail->next;
            tail->next=nullptr;
        }
    }
    void display() {
        if (head == nullptr) {
            cout << "Empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->element << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    int searchElement(int e) {
        Node* temp = head;
        int c=1;
        while (temp != nullptr) {
            if (temp->element == e)
                return c;
            temp = temp->next;
            c++;
        }

        return false;
    }
    int addAtPosition(int e, int pos) {
        Node* n = new Node(e);
        if(head==nullptr){
            if(pos!=1) return 0;
            AddAtBeginning(e);
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp == tail) {
            AddAtEnd(e);
        } else {
            n->next = temp->next;
            n->prev = temp;
            if (temp->next != nullptr)
                temp->next->prev = n;
            temp->next = n;
        }
        return 0;
    }

    void removeAtPosition(int pos) {
        if (head == nullptr) {
            cout << "Empty" << endl;
            return;
        }
        if (pos == 1) {
            RemoveAtBeginning();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos && temp != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position out of bounds." << endl;
        } else if (temp == tail) {
            RemoveAtEnd();
        } else {
            temp->prev->next = temp->next;
            if (temp->next != nullptr)
                temp->next->prev = temp->prev;
            delete temp;
        }
    }
    void reverse() {
        if (head == nullptr) {
            cout << "Empty" << endl;
            return;
        }
        Node* temp = nullptr;
        Node* current = head;
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->next;
        }
        if (temp != nullptr) {
            tail = head;
            head = temp->prev;
        }
}
};

int main() {
    DoublyLinkedList list;

    int choice=1, element, position;

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
                cout << "Enter element to be added: ";
                cin >> element;
                cout << "Enter position: ";
                cin >> position;
                list.addAtPosition(element, position);
                break;

            case 8:
                cout << "Enter position to be removed: ";
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