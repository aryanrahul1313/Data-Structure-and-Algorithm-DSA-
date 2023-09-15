//Approach 1: Recursion + Memoization
class Solution {
public:
    int solveRecMem(int start, int end, vector<vector<int>> &dp){
        if(start >= end){
            return 0;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        int maxi = INT_MAX;

        for(int i=start; i<=end; i++){
            int ans = max(solveRecMem(start, i-1, dp), solveRecMem(i+1, end, dp));
            maxi = min(maxi, i + ans);
        }
        return dp[start][end] = maxi;
    }

    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solveRecMem(1, n, dp);
    }
};

******************************************************************************************
//Approach 2: Tabulation
class Solution {
public:
    int solveTab(int n){
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));

        for(int start=n; start>=1; start--){
            for(int end=start; end<=n; end++){
                if(start == end){
                    continue;
                }
                else{
                    int maxi = INT_MAX;
                    for(int i=start; i<=end; i++){
                        int ans = max(dp[start][i-1], dp[i+1][end]);
                        maxi = min(maxi, i + ans);
                    }
                    dp[start][end] = maxi;
                }
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        return solveTab(n);
    }
};
