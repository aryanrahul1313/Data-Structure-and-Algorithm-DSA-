//Approach 1: Recursion + Memoization
class Solution {
public:
    int solveRecMem(vector<int>& satisfaction, int index, int time, vector<vector<int>> &dp)
    {
        //base case
        if(index == satisfaction.size()){
            return 0;
        }

        if(dp[index][time] != -1){
            return dp[index][time];
        }

        int include = satisfaction[index]*(time+1) + solveRecMem(satisfaction, index+1, time+1, dp);
        int exclude = solveRecMem(satisfaction, index+1, time, dp);

        dp[index][time] = max(include, exclude);

        return dp[index][time];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        sort(satisfaction.begin(), satisfaction.end());
        return solveRecMem(satisfaction, 0, 0, dp);
    }
};

*************************************************************************************************************
//Approach 2: Tabulation
class Solution {
public:
    int solveTab(vector<int>& satisfaction){
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for(int index =n-1; index>=0; index--){
            for(int time=index; time>=0; time--){
                int include = satisfaction[index]*(time+1) + dp[index+1][time+1];
                int exclude = dp[index+1][time];

                dp[index][time] = max(include, exclude);
            }
        } 
        return dp[0][0];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        return solveTab(satisfaction);
    }
};

***************************************************************************************
//Approach 3:Space Optimization
class Solution {
public:
    int solveSpaceOpt(vector<int>& satisfaction){
        int n = satisfaction.size();
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        for(int index =n-1; index>=0; index--){
            for(int time=index; time>=0; time--){
                int include = satisfaction[index]*(time+1) + next[time+1];
                int exclude = next[time];

                curr[time] = max(include, exclude);
            }
            next = curr;
        }
        return next[0];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        return solveSpaceOpt(satisfaction);
    }
};
