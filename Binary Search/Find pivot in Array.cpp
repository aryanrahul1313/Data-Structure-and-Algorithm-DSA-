#include<bits/stdc++.h>
using namespace std;

int getPivot(int arr[], int n){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    while(s<e){
        if(arr[0]<=arr[mid]){
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int main(){
    int arr[5] = {10,13,1,2,7};
    int ans = getPivot(arr,5);
    cout<<ans;

   return 0;
}
