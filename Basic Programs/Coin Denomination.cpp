#include<iostream>
using namespace std;

int main(){
    int money;
    cin>>money;
    int R100, R50, R20, R1;
    switch(1){
        case 1: R100 = money/100;
            money = money%100;
            cout<<R100<<" notes of 100 required"<<endl;

        case 2: R50 = money/50;
            money = money%50;
            cout<<R50<<" note of 50 required"<<endl;

        case 3: R20 = money/20;
            money = money%20;
            cout<<R20<<" note of 20 required"<<endl;

        case 4: R1 = money/1;
            money = money%1;
            cout<<R1<<" coins of 1 required"<<endl;

        }
   return 0;
}
