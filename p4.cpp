//20 30 40 50 5 6 7 8 9 10 11 12
//1 1 2 2 2 2 3 3 4

#include <iostream>
using namespace std;
int searchKey(int* arr, int s, int e){
    if(s>e){
        return -1;
    }
    int m = (s+e)/2;
    if(arr[m]<arr[m-1]){
        return m;
    }

    if(arr[m]>arr[e]){
        return searchKey(arr, m+1, e);
    } else{
        return searchKey(arr, s, m-1);
    }
}

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cout<<"Enter an element : ";
        cin>>arr[i];
    }
    cout<<"Key of Arr is : "<<searchKey(arr, 0, n-1);

    return 0;
}