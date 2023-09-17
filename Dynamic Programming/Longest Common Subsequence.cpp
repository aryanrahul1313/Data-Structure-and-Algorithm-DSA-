//Approach 1: Recursion + Memoization
class Solution {
public:
int solveRecMem(string &a, string &b, int i, int j, vector<vector<int>> &dp){
    if(i == a.length()){
        return 0;
    }

    if(j == b.length()){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int ans = 0;
    if(a[i] == b[j]){
        ans = 1 + solveRecMem(a, b, i+1, j+1, dp);
    }
    else{
        ans = max(solveRecMem(a, b, i+1, j, dp), solveRecMem(a, b, i, j+1, dp));
    }
    return dp[i][j] = ans;
}

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return solveRecMem(text1, text2, 0, 0, dp);
    }
};

**************************************************************************************
//Approach 2: Tabulation
class Solution {
public:
    int solveTab(string a, string b){
        int n1 = a.length();
        int n2 = b.length();
        vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));

        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = 1 + dp[i+1][j+1];
                }
                else{
                    ans = max(dp[i+1][j], dp[i][j+1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        return solveTab(text1, text2);
    }
};

******************************************************************************
//Approach 3: Space Optimization
class Solution {
public:
    int solveSpaceOpt(string a, string b){
        int n1 = a.length();
        int n2 = b.length();
    
        vector<int> curr(n2+1, 0);
        vector<int> next(n2+1, 0);

        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = 1 + next[j+1];
                }
                else{
                    ans = max(next[j], curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        return solveSpaceOpt(text1, text2);
    }
};
