//Approach 1: Recursion + Memoization
class Solution {
public:
    int solveRecMem(string &a, string &b, int i, int j, vector<vector<int>> &dp){
        int n1 = a.length();
        int n2 =b.length();
        //base case
        if(i == n1){
            return (n2-j);
        }

        if(j == n2){
            return (n1-i);
        } 

        if(dp[i][j] != -1){
            return dp[i][j];
        }   

        int ans = 0;
        if(a[i] == b[j]){
            return solveRecMem(a, b, i+1, j+1, dp);
        }
        else{
            //insert
            int insertAns = 1 + solveRecMem(a, b, i, j+1, dp);
            //delete
            int deleteAns = 1 + solveRecMem(a, b, i+1, j, dp);
            //replace
            int replaceAns = 1 + solveRecMem(a, b, i+1, j+1, dp);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return dp[i][j] = ans;
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return solveRecMem(word1, word2, 0, 0, dp);
    }
};

//Approach 2: Tabulation
class Solution {
public:
    int solveTab(string a, string b){
        int n1 = a.length();
        int n2 = b.length();
        vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));

        for(int j=0; j<n2; j++){
            dp[n1][j] = n2 - j;
        }

        for(int i=0; i<n1; i++){
            dp[i][n2] = n1 - i;
        }

        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = dp[i+1][j+1];
                }
                else{
                    //insert
                    int insertAns = 1 + dp[i][j+1];
                    //delete
                    int deleteAns = 1 + dp[i+1][j];
                    //replace
                    int replaceAns = 1 + dp[i+1][j+1];

                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        
        return solveTab(word1, word2);
    }
};

**********************************************************************************
//Approach 3: Space Optimization
class Solution {
public:
    int solveSpaceOpt(string a, string b){
        int n1 = a.length();
        int n2 = b.length();
       
        vector<int> curr(n2+1, 0);
        vector<int> next(n2+1, 0);

        for(int j=0; j<n2; j++){
            next[j] = n2 - j;
        }

        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                //Imp catch here - basae case se mila h
                curr[n2] = n1 - i;  

                int ans = 0;
                if(a[i] == b[j]){
                    ans = next[j+1];
                }
                else{
                    //insert
                    int insertAns = 1 + curr[j+1];
                    //delete
                    int deleteAns = 1 + next[j];
                    //replace
                    int replaceAns = 1 + next[j+1];

                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();

        if(n1 == 0){
            return n2;
        }

        if(n2 == 0){
            return n1;
        }
        
        return solveSpaceOpt(word1, word2);
    }
};
