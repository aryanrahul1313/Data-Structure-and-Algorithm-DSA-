#include<iostream>
using namespace std;

int isSorted(int arr[], int n){
    if(n==1 || n==0){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool remaining = isSorted(arr+1,n-1);
        return remaining;
    }
}

int main(){
    int arr[5] = {1,3,5,7,9};
    int size = 5;

    bool ans = isSorted(arr,size);

    if(ans){
        cout<<"Array is sorted "<<endl;
    }
    else{
        cout<<"Array is not sorted "<<endl;
    }

   return 0;
}
