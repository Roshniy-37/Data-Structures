#include<iostream>
#include<stack>
using namespace std;
void display(stack<int> s) {
    if (s.empty()) {
        cout << "Underflow" << endl;
        return;
    }
    cout << "Stack elements: ";
    while (!s.empty()) {
        int n = s.top();
        s.pop();
        cout << n << " ";
    }
    cout << endl;
}
int main(){
    stack<int> s;
    int n;
    cout<<"enter the element to be added: ";
    cin>>n;
    s.push(n);
    cout<<"enter the element to be added: ";
    cin>>n;
    s.push(n);
    cout<<"enter the element to be added: ";
    cin>>n;
    s.push(n);
    display(s);
    s.pop();
    display(s);
    s.size();
    s.top();
    s.empty();
}