#include<iostream>
using namespace std;
int fact(int n){
    int m = 1;
    for(int i=2; i<=n; i++){
        m=m*i;
    }
    return m;
}
int factRec(int n){
    if(n==0){
        return 1;
    }
    else{
        return n*factRec(n-1);
    }
}
int arraySum(int n, int *a){
    int sum = 0;
    for(int i=0; i <n; i++){
        sum+=a[i];
    }
    return sum;
}
int arraySumRec(int n, int *a, int sum){
    if(n==0){
        return sum;
    }
    return a[n] += arraySumRec(n-1, a, sum);
}
int arrayReverse(int n, int *a){
   for(int i = 0, j = n-1; i < j; i++, j--) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    for(int i=0; i<n; i++){
        cout<< a[i];
    }
    return a[0];
    
}
void arrayReverseRec(int *a, int s, int e){
    if(s<e){
        int temp = a[s];
        a[s]= a[e];
        a[e]= temp;
        arrayReverseRec(a, s+1, e-1);
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
    // cout<<factRec(5);
    // int a[] ={1,2,3,4,5};
    arrayReverseRec(a,0,4);
    for(int i=0; i<5; i++){
        cout<< a[i];
    }
    return 0;
}