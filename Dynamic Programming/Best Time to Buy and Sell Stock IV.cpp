//Approach 1: Recursion + Memoization
class Solution {
public:
    int solveRecMem(int index, int operationNo, int k, vector<int>& prices, vector<vector<int>> &dp)
    {
        if(index == prices.size()){
            return 0;
        }

        if(operationNo == 2*k){
            return 0;
        }

        if(dp[index][operationNo] != -1){
            return dp[index][operationNo];
        }

        int profit = 0;

        if(operationNo%2 == 0){
            int buyKaro = -prices[index] + solveRecMem(index+1, operationNo+1, k, prices, dp);
            int skipBuy = solveRecMem(index+1, operationNo, k, prices, dp);
            profit = max(buyKaro, skipBuy);
        }
        else{
            int sellKaro = prices[index] + solveRecMem(index+1, operationNo+1, k, prices, dp);
            int skipSell = solveRecMem(index+1, operationNo, k, prices, dp);
            profit = max(sellKaro, skipSell);
        }
        return dp[index][operationNo] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2*k, -1));
        return solveRecMem(0, 0, k, prices, dp);
    }
};

**********************************************************************************************************
//Approach 2: Tabulation
class Solution {
public:
    int solveTab(vector<int>& prices, int k){
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2*k+1, 0));

        for(int index=n-1; index>=0; index--){
            for(int operationNo=0; operationNo<2*k; operationNo++){
                int profit = 0;

                if(operationNo%2 == 0){
                    int buyKaro = -prices[index] + dp[index+1][operationNo+1];
                    int skipBuy = dp[index+1][operationNo];
                    profit = max(buyKaro, skipBuy);
                }
                else{
                    int sellKaro = prices[index] + dp[index+1][operationNo+1];
                    int skipSell = dp[index+1][operationNo];
                    profit = max(sellKaro, skipSell);
                }
                dp[index][operationNo] = profit;
            }
        }
        return dp[0][0];
    }

    int maxProfit(int k, vector<int>& prices) {
        return solveTab(prices, k);
    }
};

***************************************************************************************
//Approach 3: Space Optimised approach using 3D vector.
class Solution {
public:
    int solveSpaceOpt(vector<int>& prices, int k){
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int> (k+1, 0));
        vector<vector<int>> next(2, vector<int> (k+1, 0));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                for(int limit=1; limit<=k; limit++){
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
        return next[1][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        return solveSpaceOpt(prices, k);
    }
};

**************************************************************************************
//Approach 4: Space Optimised approach using 2D vector.
class Solution {
public:
    int solveSpaceOpt(vector<int>& prices, int k){ //2d vector use
        int n = prices.size();
        vector<int> curr(2*k+1, 0);
        vector<int> next(2*k+1, 0);

        for(int index=n-1; index>=0; index--){
            for(int operationNo=0; operationNo<2*k; operationNo++){
                int profit = 0;

                if(operationNo%2 == 0){
                    int buyKaro = -prices[index] + next[operationNo+1];
                    int skipBuy = next[operationNo];
                    profit = max(buyKaro, skipBuy);
                }
                else{
                    int sellKaro = prices[index] + next[operationNo+1];
                    int skipSell = next[operationNo];
                    profit = max(sellKaro, skipSell);
                }
                curr[operationNo] = profit;
            }
            next = curr;
        }
        return next[0];
    }

    int maxProfit(int k, vector<int>& prices) {
        return solveSpaceOpt(prices, k);
    }
};
