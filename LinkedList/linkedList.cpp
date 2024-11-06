#include <iostream>
using namespace std;
class Node{
    public:
        int element;
        Node* next;
        Node(){
            element = 0;
            next = nullptr;
        }
        Node(int e){
        element = e;
        next = nullptr;
        }
};
class ll{
    int count;
    Node* head;
    ll(){
        count = 0;
        head = nullptr;
    }
    int addNodeAtEnd(int e){
        Node* n = new Node(e);
        if(head == nullptr){
            head = n;
            count++;
        }else if(head->next==nullptr){
            head->next=n;
            count++;
            return 0;
        };
        Node* temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        };
        temp->next=n;
        return 0;
    }
};