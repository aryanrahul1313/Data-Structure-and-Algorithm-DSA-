#include <bits/stdc++.h>
using namespace std;

bool collection(long long int arr[],long long int n,long long int m,long long int mid){
	double sum = 0;
	for(long long int i=0;i<n;i++){
		if(arr[i] > mid){
			sum = sum + (arr[i] - mid);
		}
	}
	if(sum >= m){
        return true;
	}
	else{
        return false;
	}
}

long long int eko(long long int arr[],long long int n,long long int m){
    sort(arr,arr+n);
	long long int s = 0;
	long long int maxi = -1;
	for(long long int i=0;i<n;i++){
		maxi = max(maxi,arr[i]);
	}
	long long int e = maxi;
	long long int ans = -1;
	long long int mid = s + (e-s)/2;
	while(s <= e){
        if(collection(arr,n,m,mid)){
            ans = mid;
			s = mid + 1;
        }
		else{
			e = mid - 1;
		}
		mid = s + (e-s)/2;
	}
	return ans;
}

int main() {
	long long int n,m;
	cin>>n>>m;
	long long int arr[n];
	for(long long int i=0;i<n;i++){
        cin>>arr[i];
	}

	cout<<eko(arr,n,m)<<endl;

	return 0;
}
