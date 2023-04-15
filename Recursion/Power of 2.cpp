#include<iostream>
using namespace std;

int power(int n){
    if(n==0)     //base case
        return 1;
    //recursive relation
    return 2*power(n-1);

}

int main(){
    int num;
    cin>>num;
    int ans = power(num);
    cout<<ans<<endl;

   return 0;
}
