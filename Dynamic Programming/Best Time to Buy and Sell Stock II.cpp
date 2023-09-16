//Approach 1: Recursion + Memoization
class Solution {
public:
    int solveRecMem(int index, int buy, vector<int>& prices, vector<vector<int>> &dp)
    {
        if(index == prices.size()){
            return 0;
        }

        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        int profit = 0;

        if(buy){
            int buyKaro = -prices[index] + solveRecMem(index+1, 0, prices, dp);
            int skipBuy = solveRecMem(index+1, 1, prices, dp);
            profit = max(buyKaro, skipBuy);
        }
        else{
            int sellKaro = prices[index] + solveRecMem(index+1, 1, prices, dp);
            int skipSell = solveRecMem(index+1, 0, prices, dp);
            profit = max(sellKaro, skipSell);
        }
        return dp[index][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return solveRecMem(0, 1, prices, dp);
    }
};

***********************************************************************************************
//Approach 2: Tabulation
class Solution {
public:
    int solveTab(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                int profit = 0;

                if(buy){
                    int buyKaro = -prices[index] + dp[index+1][0];
                    int skipBuy = dp[index+1][1];
                    profit = max(buyKaro, skipBuy);
                }
                else{
                    int sellKaro = prices[index] + dp[index+1][1];
                    int skipSell = dp[index+1][0];
                    profit = max(sellKaro, skipSell);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
    
    int maxProfit(vector<int>& prices) {
        return solveTab(prices);
    }
};

**********************************************************************************
//Approach 3: Space Optimization
class Solution {
public:
    int solveSpaceOpt(vector<int>& prices){
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                int profit = 0;

                if(buy){
                    int buyKaro = -prices[index] + next[0];
                    int skipBuy = next[1];
                    profit = max(buyKaro, skipBuy);
                }
                else{
                    int sellKaro = prices[index] + next[1];
                    int skipSell = next[0];
                    profit = max(sellKaro, skipSell);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
    
    int maxProfit(vector<int>& prices) {
        return solveSpaceOpt(prices);
    }
};
