#include <bits/stdc++.h>

int modularExponentiation(long x, long n, long m) {
	int ans = 1;
    while(n > 0){
        if(n&1){    //n is odd
           ans = (ans * x) %m;
        }
        x = (x * x)%m;   
        n = n>>1;  //divide by 2
    }
    return ans;
}
