//Approach 1: Recursion + Memoization
#include <bits/stdc++.h> 
#define MOD 1000000007

int add(int a, int b){
    return (a%MOD + b%MOD) % MOD;
}

int mul(int a, int b){
    return ((a%MOD) * 1LL * (b%MOD)) % MOD;
}

int solve(int n, int k, vector<int> &dp){
    //base case
    if(n == 1){
        return k;
    }
    if(n == 2){
        return add(k, mul(k, k-1));
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = add(mul(solve(n-2, k, dp), k-1) , mul(solve(n-1, k, dp), k-1));

    return dp[n];

}

int numberOfWays(int n, int k) {
    vector<int> dp(n+1, -1);
    return solve(n, k, dp);
}

************************************************************************************
//Approach 2 : Tabulation
#include <bits/stdc++.h> 
#define MOD 1000000007

int add(int a, int b){
    return (a%MOD + b%MOD) % MOD;
}

int mul(int a, int b){
    return ((a%MOD) * 1LL * (b%MOD)) % MOD;
}

int solve(int n, int k){
    vector<int> dp(n+1, 0);
    dp[1] = k;
    dp[2] = add(k, mul(k, k-1));

    for( int i=3; i<=n; i++){
        int same = mul(dp[i-2], k-1);
        int diff = mul(dp[i-1], k-1);
        int sum = add(same, diff);
        dp[i] = sum;
    }
    return dp[n];
}

int numberOfWays(int n, int k) {
    return solve(n, k);
}
