#include <iostream>
#include <queue>
#include <iomanip> 
using namespace std;

class Node {
public:
    int data, height;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        height = 1; 
        left = right = nullptr;
    }
};

int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    x->right = y;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    else
        return root; 

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1) {
        if (val < root->left->data) {
            return rotateRight(root); 
        } else {
            root->left = rotateLeft(root); 
            return rotateRight(root);
        }
    }

    if (balance < -1) {
        if (val > root->right->data) {
            return rotateLeft(root); 
        } else {
            root->right = rotateRight(root);  
            return rotateLeft(root);
        }
    }

    return root;
}


bool search(Node* root, int val) {
    if (!root) return false;
    if (root->data == val) return true;
    if (val < root->data) return search(root->left, val);
    return search(root->right, val);
}

void breadthFirstTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

void display(Node* root, int level = 0, string prefix = "") {
    if (root == nullptr) return;

    cout << prefix << "Level " << level << ": " << root->data << endl;
    if (root->left || root->right) {
        if (root->left) {
            cout << prefix << "L---";
            display(root->left, level + 1, prefix + "    ");
        } else {
            cout << prefix << "L---" << "NULL" << endl;
        }

        if (root->right) {
            cout << prefix << "R---";
            display(root->right, level + 1, prefix + "    ");
        } else {
            cout << prefix << "R---" << "NULL" << endl;
        }
    }
}

int main() {
    Node* root = nullptr;
    int choice, value;

    while (choice != 5){
        cout << "\nAVL Tree Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Breadth-First Traversal\n";
        cout << "4. Display Tree\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value))
                    cout << "Value found in the tree.\n";
                else
                    cout << "Value not found.\n";
                break;
            case 3:
                cout << "Breadth-First Traversal: ";
                breadthFirstTraversal(root);
                cout << endl;
                break;
            case 4:
                cout << "Tree Structure: \n";
                display(root); 
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } 

    return 0;
}
