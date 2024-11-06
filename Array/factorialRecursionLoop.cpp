#include <iostream>
using namespace std;

int recFact(int n){
    if(n==1 || n==2){
        return n;
    }

    return n * recFact(n-1);
}

int main(){
    int n, loopFact = 1;
    cout<<"Enter a number : ";
    cin>>n;

    for(int i=2; i<=n; i++){
        loopFact *= i;
    }

    cout<<"Factorial of n using loop : "<<loopFact<<endl;
    cout<<"Factorial of n using recursion : "<<recFact(n)<<endl;

    return 0;
}