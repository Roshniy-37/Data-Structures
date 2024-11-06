#include <iostream>
#include <queue>
using namespace std;
class Node{
public:
    int data;
    Node *left, *right;
    Node(){
        data=-1;
        left = right = NULL;
    }
    Node(int e){
        data = e;
        left = right = NULL;
    }
};
class Tree{
public:
    Node *root;
    int count;
    Tree(){
        root = NULL;
        count = 0;
    }
    void insert1(int e){
        Node *n = new Node(e);
        if(!root){
            root = n;
            count++;
            return;
        }
        Node *temp = root;
        Node *prev = NULL;
        while(temp!=NULL){
            prev = temp;
            if(temp->data<e){
                temp=temp->right;
            }else{
                temp=temp->left;
            }
        }
        if(e < prev->data){
            prev->left = n;
        }else{
            prev->right = n;
        }
        count++;
        return;
    }
    void insert2(int e){
        Node *n = new Node(e);
        if(!root){
            root = n;
            count++;
            return;
        }
        Node *temp = root;
        while (true){
           if(temp->data<e){
            if(!temp->right){
                temp->right=n;
                break;
            }
            else{
                temp=temp->right;
            }
           }else{
            if(!temp->left){
                temp->left=n;
                break;
            }else{
                temp=temp->left;
            }
           }
        }
        count++;
        return;  
    }
    Node* search(int e){
        if(!root){
            return NULL;
        }
        Node* temp = root;
        while(temp && temp->data!=e){
            if(e<temp->data){
                temp=temp->left;
            }else{
                temp=temp->right;
            }
        }
        return temp;
    }
    void display(){
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left != NULL) {
                q.push(current->left);
            }
            if (current->right != NULL) {
                q.push(current->right);
            }
        }
        cout << endl;
    }
};

int main(){
    Tree t;
    int choice = -1, value;

    while (choice != 0){
        cout << "\nMenu:\n";
        cout << "1. Insert 1\n";
        cout << "2. Insert 2\n";
        cout << "3. Search \n";
        cout << "4. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to be inserted: ";
                cin >> value;
                t.insert1(value);
                break;
            case 2:
                cout << "Enter the value to be inserted: ";
                cin >> value;
                t.insert2(value);
                break;
            case 3:
                cout << "Enter the value to be searched: ";
                cin >> value;
                if(t.search(value)){
                    cout << "Found" << endl;
                }else{
                    cout << "Not found" << endl;
                }
                break;
            case 4:
                t.display();
                break;
            case 0:
                cout << "Exited" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
    return 0;
}