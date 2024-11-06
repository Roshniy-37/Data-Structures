//20 30 40 50 5 6 7 8 9 10 11 12
#include <iostream>
using namespace std;
int arrShift(int* arr, int s, int e){
    if(s>e){
        return -1;
    }
    int mid = (s+e)/2;
    if(arr[mid]<arr[mid-1]){
        return mid;
    }

    if(arr[mid]<arr[s]){
        return arrShift(arr, s, mid-1);
    } else{
        return arrShift(arr, mid+1, e);
    }
}

int main(){
    int n;
    cout<<"Enter number of elements in array : ";
    cin>>n;
    int *p = new int[n];
    for(int i=0; i<n; i++){
        cout<<"Enter an element : ";
        cin>>p[i];
    }
    cout<<"Array is unordered at : "<<arrShift(p, 0, n-1);

    return 0;
}