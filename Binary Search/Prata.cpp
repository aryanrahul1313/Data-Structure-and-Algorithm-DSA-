#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> &rank, int p, int mid){
    int prata = 0;
	for(int i=0;i<(int)rank.size();i++){
		int a = 1,t = mid;
		while(t-(a*rank[i])>=0){
			prata++;
			t -= (a*rank[i]);
			a++;
		}
	}
	return prata>=p;
}

void rotiPrata(){
    int p;
    cin>>p;
    int n;
    cin>>n;
    vector<int> rank(n);
    for(int i=0;i<n;i++){
        cin>>rank[i];
    }
    int s = 0;
    int e = 5000000;
    int ans = -1;
    int mid = s + (e-s)/2;
    while(s <= e){
        if(check(rank,p,mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
	while(t--){
	    rotiPrata();
    }

   return 0;
}


