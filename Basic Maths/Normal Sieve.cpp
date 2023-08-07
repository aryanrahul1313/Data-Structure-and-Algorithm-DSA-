#include <bits/stdc++.h>
using namespace std;

vector<long long> normalSieve(long long R) {
        long long n = sqrt(R);
        vector<bool> prime(n+1,true);
        prime[0] = prime[1] = false;
        vector<long long> ans;
        for(long long p=2; p<n; p++) {
            if(prime[p]){
                ans.push_back(p);
                for(long long i=2*p; i<n; i+=p){
                    prime[i] = false;
                }
            }
        }
        return ans;
    }

int main() {
    int R;
    cin >> R;
    vector<long long> result;
    result = normalSieve(R);
    for(long long i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
