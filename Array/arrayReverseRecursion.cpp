#include <iostream>

using namespace std;
void revArr(int arr[], int i, int j);
void printArr(int arr[], int n);

int main(){
    int n;
    cout<<"Number of elements in the array : ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cout<<"Enter an element : ";
        cin>>arr[i];
    }
    revArr(arr, 0, n-1);
    cout<<"Array after reversal : ";
    printArr(arr, n);

    return  0;
}

void revArr(int arr[], int i, int j){
    if(i>=j){
        return;
    } else{
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        revArr(arr, i+1, j-1);
    }
}

void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}