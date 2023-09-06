//Approach 1: Recursion + Memoization

#include<bits/stdc++.h>
using namespace std;

int fib(int n, vector<int> &dp){
        //base case
        if(n <= 1){
           return n;
        }

        //step 3:
        if(dp[n] != -1){
           return dp[n];
        }

        //step 2:
        dp[n] = fib(n-1, dp) + fib(n-2, dp);
        return dp[n];
}

int main()
{
        int n;
        cin >> n;

        //step 1:
        vector<int> dp(n+1);
        for(int i=0; i<=n; i++){
                dp[i] = -1;
        }

        cout<< fib(n, dp)<<endl;

        return 0;
}
********************************************************************************


//Approach 2: Tabulation
#include<bits/stdc++.h>
using namespace std;

int main()
{
        int n;
        cin >> n;

        //step 1:
        vector<int> dp(n+1);

        //step 2:
        dp[0] = 0;
        dp[1] = 1;

        //step 3:
        for(int i=2; i<=n; i++){
                dp[i] = dp[i-1] + dp[i-2];
        }

        cout<< dp[n] <<endl;

        return 0;
}
********************************************************************


//Approach 3: Space Optimization
#include<bits/stdc++.h>
using namespace std;

int main()
{
        int n;
        cin >> n;

        int prev1 = 0;
        int prev2 = 1;

        for(int i=2; i<=n; i++){
            int curr = prev1 + prev2;
            //shift logic
            prev1 = prev2;
            prev2 = curr;
        }

        cout<< prev2 <<endl;

        return 0;
}
