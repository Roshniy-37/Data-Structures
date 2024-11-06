#include<iostream>
using namespace std;
template <typename T>
class CircularQueue{
private:
    int cap;
    T *arr;
    int front, rear;
public:
    CircularQueue(int c){
        cap = c;
        arr = new T[c];
        front= rear = -1;
    }
    bool isEmpty(){
        if(rear==-1)
            return true;
        return false;
    }
    bool isFull(){
        if((rear+1)%cap==front)
            return true;
        return false;
    }
    void enqueue(T e){
        if(isEmpty()){
            front=0;
            rear=0;
            arr[rear]=e;
        }else if(!isFull()){
            rear = (rear+1)%cap;
            arr[rear]=e;
        }
        else{
            cout<<"Queue is Full";
        }
    }
    T dequeue(){
        if(!isEmpty()){
            T t = arr[front];
            if(front==rear){
                front=rear=-1;
            }else{
                front=(front+1)%cap;
            }
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
        if(front<rear){
            for(int i=front; i<=rear; i++){
                T e= dequeue(); 
                cout << e << " "; 
                enqueue(e); 
            }
        }else if(front>rear){
            for(int i=front; i<cap; i++){
                T e= dequeue(); 
                cout << e << " "; 
                enqueue(e); 
            }
            for(int i=0; i<=rear; i++){
                T e= dequeue(); 
                cout << e << " "; 
                enqueue(e); 
            }
        }
        else{
            T e= dequeue(); 
            cout << e << " "; 
            enqueue(e); 
        }
        cout << endl; 
    }
};
int main(){
    CircularQueue<int> q(6); 
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
                cout << "Dequeued element: " << q.dequeue() << endl;
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