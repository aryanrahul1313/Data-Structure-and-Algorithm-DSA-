#include<iostream>
using namespace std;

bool linearSearch(int arr[], int n, int target){
    if(n==0)
        return false;

    if(arr[0]==target){
        return true;
    }
    else{
        bool remaining = linearSearch(arr+1,n-1,target);
        return remaining;
    }
}

int main(){
    int arr[5] = {1,3,5,7,9};
    int size = 5;
    int target;
    cin>>target;

    bool ans = linearSearch(arr,size,target);

    if(ans){
        cout<<"Found "<<endl;
    }
    else{
        cout<<"Not found "<<endl;
    }

   return 0;
}
