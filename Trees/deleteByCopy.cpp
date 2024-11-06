#include<iostream>
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
    int deleteNode(int e){
        if(!root)return 1;
        Node* temp = root, *par = NULL;
        while(temp && temp->data!=e){
            par = temp;
            if(e<temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if(!temp)
            return 1;
        deleteByCopy(par, temp);
    }
    int deleteByCopy(Node* par, Node* temp){
        
        if(!temp->left && !temp->right){
            if(temp->data<par->data)
                par->left= NULL;
            else
                par->right = NULL;
            delete temp;
        }else if(!temp->left){
            if(temp->data<par->data){
                par->left = temp->right;
            }else{
                par->right = temp->right;
            }
            delete temp;
        }else if(!temp->right){
            if(temp->data<par->data){
                par->left = temp->left;
            }else{
                par->right = temp->left;
            }
            delete temp;
        }else{
            Node* succ = temp->right;
            while(succ->left)
                succ = succ->left;
            temp->data = succ->data;
            deleteByCopy(par, succ);
        }
    }
};