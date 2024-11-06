#include <iostream>
using namespace std;

int firstInst(int* arr, int ele, int s, int e){
    if(s>e){
        return -1;
    }
    int mid = (s+e)/2;
    
    if(arr[mid] == ele){
        if(arr[mid-1] != ele){
            return mid;
        }
        else{
            firstInst(arr, ele, s, mid);
        }
    } else if(arr[mid] > ele){
        firstInst(arr, ele, s, mid-1);
    } else{
        firstInst(arr, ele, mid+1, e);
    }
}

int main(){
    int n;
    cout<<"Enter number of elements in the array : ";
    cin>>n;

    int *p = new int[n];
    for(int i=0; i<n; i++){
        cout<<"Enter an element : ";
        cin>>p[i];
    }

    int ele;
    cout<<"Enter element to search : ";
    cin>>ele;

    cout<<"First instance of element : "<<firstInst(p, ele, 0, n-1);
    return 0;
}