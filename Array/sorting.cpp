#include<iostream>
using namespace std;
void insertionSort(int *a, int n){
    for(int i=0; i<n; i++){
        int j=i;
        int temp = a[i];
        while(j>0 && temp <a[j-1]){
            a[j]=a[j-1];
            j--;
        }
    }
}
int main(){
    int *a;
    int n=5;
    a = new int[n];
    for(int i=0; i<n; i++){
        cout<<"enter";
        cin>>a[i];
    }
   insertionSort(a, 5);
    for(int i=0; i<5; i++){
        cout<< a[i];
    }
    return 0;
}