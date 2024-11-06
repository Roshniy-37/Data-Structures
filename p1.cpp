#include<iostream>
using namespace std;

int Linear_Sum(int arr[], int i, int n){
    if(i == n){
        return 0;
    }else{
        return arr[i]+Linear_Sum(arr, i+1, n);
    }
}
int Binary_Sum(int arr[], int i, int n){
    if(n==1){
        return arr[i];
    }else{
        return Binary_Sum(arr, i,n/2) + Binary_Sum(arr, i + (n/2), n/2);
    }
}
int Fib(int a, int b, int n){
    cout<<b<<" ";
    if(n==0){
        return b;
    }if(n==1){
        return b;
    }else{
        return Fib(b, a+b, n-1);
    }
}
int main(){
    // int arr[] = {1,2,3,4,6,7,90};
    // int n = sizeof(arr) / sizeof(int);
    // cout<<Binary_Sum(arr, 0, n);
    cout<<Fib(0, 1,12 );
    return 0;
}