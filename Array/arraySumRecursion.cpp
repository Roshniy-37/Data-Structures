#include <iostream>
using namespace std;

int arrSum(int arr[], int n);

int main(){
    int n;
    cout<<"Number of elements in the array : ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cout<<"Enter an element : ";
        cin>>arr[i];
    }
    cout<<"Sum of elements in the array : "<<arrSum(arr, n);

    return 0;
}

int arrSum(int arr[], int n){
    if(n==1){
        return arr[0];
    } else{
        return arrSum(arr, n-1) + arr[n-1];
    }
}