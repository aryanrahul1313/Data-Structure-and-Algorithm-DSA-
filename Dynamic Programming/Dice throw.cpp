//Approach 1: Recusrion + Memoization
class Solution {
  public:
    long long solveRecMem(int faces, int dice, int target, vector<vector<long long>> &dp){
        if(target < 0){
            return 0;
        }
        
        if(target == 0 && dice != 0){
            return 0;
        }
        
        if(target != 0 && dice == 0){
            return 0;
        }
        
        if(target == 0 && dice == 0){
            return 1;
        }
        
        if(dp[dice][target] != -1){
            return dp[dice][target];
        }
        
        long long ans = 0;
        for( int i=1; i<=faces; i++){
            ans = ans + solveRecMem(faces, dice-1, target-i, dp);
        }
        
        return dp[dice][target] = ans;
    }
    
    long long noOfWays(int M , int N , int X) {
        vector<vector<long long>> dp(N+1, vector<long long> (X+1, -1));
        return solveRecMem(M, N, X, dp);
    }
};

*******************************************************************************
//Approach 2: Tabulation
class Solution {
  public:
    long long solveTab(int M , int N , int X){
        vector<vector<long long>> dp(N+1, vector<long long> (X+1, 0));
        dp[0][0] = 1;
        
        for(int dice=1; dice<=N; dice++){
            for( int target=1; target<=X; target++){
                long long ans = 0;
                for( int i=1; i<=M; i++){
                    if(target-i >= 0)
                        ans = ans + dp[dice-1][target-i];
                }
                dp[dice][target] = ans;
            }
        }
        return dp[N][X];
    }
    
    long long noOfWays(int M , int N , int X) {
        return solveTab(M, N, X);
    }
};

****************************************************************************
//Approach 3: Space Optimization
class Solution {
  public:
    long long spaceOpt(int M , int N , int X){
        vector<long long> prev(X+1);
        vector<long long> curr(X+1);
        prev[0] = 1;
        
        for(int dice=1; dice<=N; dice++){
            for( int target=1; target<=X; target++){
                long long ans = 0;
                for( int i=1; i<=M; i++){
                    if(target-i >= 0)
                        ans = ans + prev[target-i];
                }
                curr[target] = ans;
            }
            prev = curr;
        }
        return prev[X];
    }
    
    long long noOfWays(int M , int N , int X) {
        return spaceOpt(M, N, X);
    }
};
