class Solution{   
public:
    // Note: dp[j][diff] means j index tk length of longest AP with 
            // common diff 'diff' kitni h...
    
    int lengthOfLongestAP(int nums[], int n) {
        // code here
        if(n <= 2){
            return n;
        }
        int m = 20001;
        
        vector<vector<int>> dp(n,vector<int>(m,1));
        
        int ans = 1;
        
        for(int i=1; i<n; i++){
        
            for(int j=0; j<i; j++){
        
                int d = (nums[i]-nums[j]+10000);
        
                dp[i][d] = 1+dp[j][d];
        
                ans = max(ans,dp[i][d]);
            }
        }
        return ans;
    }
};
