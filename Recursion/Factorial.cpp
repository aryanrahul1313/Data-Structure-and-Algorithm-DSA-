#include<iostream>
using namespace std;

int factorial(int n){
    if(n==0)
        return 1;

    return n*factorial(n-1);
}

int main(){
    int num;
    cin>>num;
    int ans = factorial(num);
    cout<<ans<<endl;

   return 0;
}
