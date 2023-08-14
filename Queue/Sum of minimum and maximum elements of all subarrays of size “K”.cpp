#include <bits/stdc++.h> 
long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	
	deque<int> maxi;
	deque<int> mini;

	// Addition of first K size window
	for(int i=0; i<k; i++){

		while(!maxi.empty() && nums[maxi.back()] <= nums[i]){
			maxi.pop_back();
		}

		while(!mini.empty() && nums[mini.back()] >= nums[i]){
			mini.pop_back();
		}

		maxi.push_back(i);
		mini.push_back(i);
	}

	long long ans = 0;
	for(int i=k; i<n; i++){
		ans += nums[maxi.front()] + nums[mini.front()]; 

		// next window

		// removal
		while(!maxi.empty() && i-maxi.front() >= k){
			maxi.pop_front();
		}

		while(!mini.empty() && i-mini.front() >= k){
			mini.pop_front();
		}

		// addition 

		while(!maxi.empty() && nums[maxi.back()] <= nums[i]){
			maxi.pop_back();
		}

		while(!mini.empty() && nums[mini.back()] >= nums[i]){
			mini.pop_back();
		}

		maxi.push_back(i);
		mini.push_back(i);
	}
	// make sure to consider last window
	ans += nums[maxi.front()] + nums[mini.front()];

	return ans;
}
