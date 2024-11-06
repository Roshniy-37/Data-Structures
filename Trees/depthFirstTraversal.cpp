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
    void preorder(Node* root){
       if(root){
        cout << root->data;
        preorder(root->left);
        preorder(root->right);
       } 
    }
    void postorder(Node* root){
        postorder(root->left);
        postorder(root->right);
        cout << root->data;
    }
    Node* inorder(Node* root){
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
};

int main(){
    Tree t;
    int choice = -1, value;

    while (choice != 0){
        cout << "\nMenu:\n";
        cout << "1. PreOrder 1\n";
        cout << "2. PostOrder 2\n";
        cout << "3. InOrder \n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Pre Order: ";
                t.preorder(t.root);
                break;
            case 2:
                cout << "Post Order: ";
                t.postorder(t.root);
                break;
            case 3:
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