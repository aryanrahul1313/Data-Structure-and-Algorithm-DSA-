#include<iostream>
using namespace std;

int setbits1(int a){
    int ca = 0;
    while(a != 0){
        if((a&1)==1){
            ca++;
        }
        a = a>>1;
    }

    return ca;
}

int setbits2(int b){
    int cb = 0;
    while(b != 0){
        if((b&1)==1){
            cb++;
        }
        b = b>>1;
    }

    return cb;
}

int main(){
    int a, b;
    cout<<"Enter value of a"<<endl;
    cin>>a;
    cout<<"Enter value of b"<<endl;
    cin>>b;

    int ans1 = setbits1(a);
    int ans2 = setbits2(b);
    int ans = ans1 + ans2;

    cout<<"No of set bits are "<<ans;

   return 0;
}
