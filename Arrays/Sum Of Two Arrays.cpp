#include <bits/stdc++.h> 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int num_a = 0;
	for(int i=1; i<=n; i++){
		num_a += a[i-1]*pow(10,n-i); 
	}

	int num_b = 0;
	for(int j=1; j<=m; j++){
		num_b += b[j-1]*pow(10,m-j); 
	}

	int ans = num_a + num_b;
	
	vector<int> arr;
	int count = 0;
	while(ans > 0){
		int mod = ans%10;
		arr.push_back(mod);
		count++;
		ans = ans/10;
	}

	int s=0, e=count-1;
	while(s <= e){
		swap(arr[s++], arr[e--]);
	}

	return arr;
}
