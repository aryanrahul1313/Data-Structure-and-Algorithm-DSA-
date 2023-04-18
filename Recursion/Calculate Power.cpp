#include<iostream>
using namespace std;

int power(int a, int b){
    if(b==0)
        return 1;
    if(b==1)
        return a;
    int ans = power(a,b/2);

    if(b&1){      //odd
        return a*ans*ans;
    }
    else{
        return ans*ans;
    }
}

int main(){
    int a;
    int b;
    cin>>a;
    cin>>b;

    int ans = power(a,b);
    cout<<ans<<endl;

   return 0;
}
