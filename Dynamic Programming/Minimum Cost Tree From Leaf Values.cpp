class Solution {
public:
    int solveRecMem(vector<int>& arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp)
    {
        // leafe node
        if(left == right){
            return 0;
        }

        if(dp[left][right] != -1){
            return dp[left][right];
        }

        int ans = INT_MAX;

        for(int i=left; i<right; i++){
            int temp = maxi[{left, i}] * maxi[{i+1, right}];
            int sol = solveRecMem(arr, maxi, left, i, dp) + solveRecMem(arr, maxi, i+1, right, dp);
            ans = min(ans, temp + sol);
        }
        return dp[left][right] = ans;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map<pair<int, int>, int> maxi;
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));

        for(int i=0; i<n; i++){
            maxi[{i,i}] = arr[i];
            for(int j=i+1; j<n; j++){
                maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
            } 
        }
        return solveRecMem(arr, maxi, 0, n-1, dp);
    }
};
