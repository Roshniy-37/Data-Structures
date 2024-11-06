//1 1 2 2 2 2 3 3 4
#include <iostream>
using namespace std;
int firstOccur(int* arr, int a, int s, int e){
    if(s>e){
        return -1;
    }
    int m = (s+e)/2;
    if(arr[m] == a){
        if(arr[m-1] != a){
            return m;
        }
        else{
            firstOccur(arr, a, s, m);
        }
    } else if(arr[m] > a){
        firstOccur(arr, a, s, m-1);
    } else{
        firstOccur(arr, a, m+1, e);
    }
}

int main(){
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cout<<"Enter the element : ";
        cin>>arr[i];
    }
    int a;
    cout<<"Enter the element to search : ";
    cin>>a;
    cout<<"First occurence of element : "<<firstOccur(arr, a, 0, n-1);
    return 0;
}