#include<iostream>
using namespace std;
template <typename T>
class Queue{
private:
    int cap;
    T *arr;
    int front, rear;
public:
    Queue(int c){
        cap = c;
        arr = new T[c];
        front= rear = -1;
    }
    bool isEmpty(){
        if(front == rear)
            return true;
        return false;
    }
    bool isFull(){
        if(rear == cap-1)
            return true;
        return false;
    }
    void enqueue(T e){
        if(!isFull()){
            rear++;
            arr[rear]=e;
        }
        else{
            cout<<"Queue is Full";
        }
    }
    // dequeue which uses O(1) time but wastes memory
    T dequeue1(){
        if(!isEmpty()){
            front++;
            return arr[front];
        }
        return -1;
    }
    // dequeue which uses O(n) time but saves memory
    T dequeue2(){
        if(!isEmpty()){
            T t = arr[0];
            for(int i=1; i<= rear; i++)
                arr[i-1]=arr[i];
            rear--;
            return t;
        }
        return -1;
    }
    void display(){
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }  
        cout << "Queue elements: ";
        for (int i = 0; i <= rear; i++) {
            T e= dequeue2(); 
            cout << e << " "; 
            enqueue(e); 
        }
        cout << endl; 
    }
};
int main(){
    Queue<int> q(6); 
    int choice = 1, value;

   while (choice != 0){
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Check if Stack is Full\n";
        cout << "5. Check if Stack is Empty\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to be push: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                cout << "Dequeued element: " << q.dequeue2() << endl;
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Is queue full? " << (q.isFull() ? "Yes" : "No") << endl;
                break;
            case 5:
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