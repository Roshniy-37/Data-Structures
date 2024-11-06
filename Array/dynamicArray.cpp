#include <iostream>
using namespace std;

void swapEle(int* p, int x, int y){
    int temp = p[x];
    p[x] = p[y];
    p[y] = temp;
}

void printArr(int* p, int n){
    for(int i=0; i<n; i++){
        cout<<p[i]<<", ";
    }
    cout<<endl;
}

int recSumArr(int* p, int n){
    if(n==0){
        return 0;
    } else if(n==1){
        return p[0];
    }

    return p[n-1] + recSumArr(p, n-1);
}

int recRevArr(int* p, int start, int end){
    if(start<end){
        swapEle(p, start, end);
        recRevArr(p, start+1, end-1);
    }
}

void loopRevArr(int *p, int n){
    for(int i=0, j=n-1; i<j; i++, j--){
        swapEle(p, i, j);
    }
}

int main(){
    int *p;
    int n, opt, sumArr = 0;
    cout<<"Enter size of dynamic array : ";
    cin>>n;
    p = new int[n];
    for(int i=0; i<n; i++){
        cout<<"Enter an element of the dynamic array : ";
        cin>>p[i];
    }
    cout<<"Your array : ";
    printArr(p, n);

    for(int i=0; i<n; i++){
        sumArr+=p[i];
    }
    cout<<"Sum of array using loop : "<<sumArr<<endl;
    cout<<"Sum of array using recursion : "<<recSumArr(p, n)<<endl<<endl;

    loopRevArr(p, n);
    cout<<"Array reversal using for loop : ";
    printArr(p, n);

    recRevArr(p, 0, n-1);
    cout<<"Reversing back to original array using recursion : ";
    printArr(p, n);
    
    return 0;
}

