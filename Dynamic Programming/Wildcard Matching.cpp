//Approach 1: Recursion + Memoization
class Solution {
public:
    bool solveRecMem(string &str, string &pattern, int i, int j, vector<vector<int>> &dp){
        //base cases
        if(i == 0 && j == 0){
            return true;
        }

        if(i>0 && j == 0){
            return false;
        }

        if(i == 0 && j>0){
            for(int k=1; k<=j; k++){
                if(pattern[k-1] != '*'){
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        //match
        if(str[i-1] == pattern[j-1] || pattern[j-1] == '?'){
            return dp[i][j] = solveRecMem(str, pattern, i-1, j-1, dp);
        }

        else if(pattern[j-1] == '*'){
            dp[i][j]  = (solveRecMem(str, pattern, i, j-1, dp) || solveRecMem(str, pattern, i-1, j, dp));
            return dp[i][j];
        }

        else{
            return false;
        }
    }

    bool isMatch(string s, string p) {
        int len1 = s.length();
        int len2 = p.length();
        vector<vector<int>> dp(len1+1, vector<int> (len2+1, -1));

        return solveRecMem(s, p, len1, len2, dp);
    }
};

************************************************************************************************************
//Approach 2: Tabulation
class Solution {
public:
    bool solveTab(string str, string pattern){
        int len1 = str.length();
        int len2 = pattern.length();
        vector<vector<int>> dp(len1+1, vector<int> (len2+1, 0));
        dp[0][0] = true;

        for(int j=1; j<=len2; j++){
            bool flag = true;
            for(int k=1; k<=j; k++){
                if(pattern[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){

                if(str[i-1] == pattern[j-1] || pattern[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }

                else if(pattern[j-1] == '*'){
                    dp[i][j]  = (dp[i][j-1] || dp[i-1][j]);
                }

                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[len1][len2];
    }

    bool isMatch(string s, string p) {

        return solveTab(s, p);
    }
};

**********************************************************************************
//Approach 3: Space Optimization
class Solution {
public:
    bool spaceOpt(string str, string pattern){
        int len1 = str.length();
        int len2 = pattern.length();
        
        vector<int> prev(len2+1, 0);
        vector<int> curr(len2+1, 0);
        prev[0] = true;

        for(int j=1; j<=len2; j++){
            bool flag = true;
            for(int k=1; k<=j; k++){
                if(pattern[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for(int i=1; i<=len1; i++){
            for(int j=1; j<=len2; j++){

                if(str[i-1] == pattern[j-1] || pattern[j-1] == '?'){
                    curr[j] = prev[j-1];
                }

                else if(pattern[j-1] == '*'){
                    curr[j]  = (curr[j-1] || prev[j]);
                }

                else{
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[len2];
    }

    bool isMatch(string s, string p) {

        return spaceOpt(s, p);
    }
};
