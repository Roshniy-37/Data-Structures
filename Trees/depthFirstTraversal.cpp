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
    void insert(int e){
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
    void preorder(Node* n){
       if(n){
            cout << n->data;
            preorder(n->left);
            preorder(n->right);
       } 
    }
    void postorder(Node* n){
        if(n){
            postorder(n->left);
            postorder(n->right);
            cout << n->data;
        }
    }
    void inorder(Node* n){
        if(n){
            inorder(n->left);
            cout << n->data;
            inorder(n->right);
        }
    }
};

int main(){
    Tree t;
    int choice = -1, value;

    while (choice != 0){
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. PreOrder\n";
        cout << "3. PostOrder\n";
        cout << "4. InOrder \n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to be inserted: ";
                cin >> value;
                t.insert(value);
                break;
            case 2:
                cout << "Pre Order: ";
                t.preorder(t.root);
                break;
            case 3:
                cout << "Post Order: ";
                t.postorder(t.root);
                break;
            case 4:
                cout << "In Order: ";
                t.inorder(t.root);
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