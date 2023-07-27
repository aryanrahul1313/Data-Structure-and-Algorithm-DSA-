#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector< vector<int> > ans;
	sort(arr.begin(),arr.end());
	for(int i=0; i<n; i++){
		int j=i+1, k=n-1;
		while(j < k){
			if(arr[j]+arr[k] < K-arr[i]){
				j++;
			}
			else if(arr[j]+arr[k] > K-arr[i]){
				k--;
			}
			else{
				int x = arr[j];
				int y = arr[k];
				ans.push_back({arr[i], arr[j], arr[k]});

				while(j<k && arr[j]==x){
					j++;
				}
				while(j<k && arr[k]==y){
					k--;
				}
			}
		}
		while(i+1<n && arr[i]==arr[i+1]){
			i++;
		}
	}
	return ans;
}
