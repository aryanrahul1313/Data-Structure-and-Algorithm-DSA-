//Approach 1: Recursion + Memoization
class Solution {
public:
    int solveRecMem(int index, int buy, vector<int>& prices, int limit, vector<vector<vector<int>>> &dp)
    {
        if(index == prices.size()){
            return 0;
        }

        if(limit == 0){
            return 0;
        }

        if(dp[index][buy][limit] != -1){
            return dp[index][buy][limit];
        }

        int profit = 0;

        if(buy){
            int buyKaro = -prices[index] + solveRecMem(index+1, 0, prices, limit, dp);
            int skipBuy = solveRecMem(index+1, 1, prices, limit, dp);
            profit = max(buyKaro, skipBuy);
        }
        else{
            int sellKaro = prices[index] + solveRecMem(index+1, 1, prices, limit-1, dp);
            int skipSell = solveRecMem(index+1, 0, prices, limit, dp);
            profit = max(sellKaro, skipSell);
        }
        return dp[index][buy][limit] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        return solveRecMem(0, 1, prices, 2, dp);
    }
};

******************************************************************************************************
//Approach 2: Tabulation
class Solution {
public:
    int solveTab(vector<int>& prices){
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                for(int limit=1; limit<=2; limit++){
                    int profit = 0;

                    if(buy){
                        int buyKaro = -prices[index] + dp[index+1][0][limit];
                        int skipBuy = dp[index+1][1][limit];
                        profit = max(buyKaro, skipBuy);
                    }
                    else{
                        int sellKaro = prices[index] + dp[index+1][1][limit-1];
                        int skipSell = dp[index+1][0][limit];
                        profit = max(sellKaro, skipSell);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }

    int maxProfit(vector<int>& prices) {
        
        return solveTab(prices);
    }
};

***************************************************************************************
//Approach 3: Space Optimization
class Solution {
public:
    int solveSpaceOpt(vector<int>& prices){
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int> (3, 0));
        vector<vector<int>> next(2, vector<int> (3, 0));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                for(int limit=1; limit<=2; limit++){
                    int profit = 0;

                    if(buy){
                        int buyKaro = -prices[index] + next[0][limit];
                        int skipBuy = next[1][limit];
                        profit = max(buyKaro, skipBuy);
                    }
                    else{
                        int sellKaro = prices[index] + next[1][limit-1];
                        int skipSell = next[0][limit];
                        profit = max(sellKaro, skipSell);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }

    int maxProfit(vector<int>& prices) { 
        return solveSpaceOpt(prices);
    }
};
