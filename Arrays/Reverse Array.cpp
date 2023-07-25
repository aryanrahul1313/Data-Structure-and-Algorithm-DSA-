#include<iostream>
using namespace std;

bool search(int arr[], int size, int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}


int main(){
   int num[50] = {1,3,5,7,9,-2,-4,-6,-8,0};
   int key;
   cout<<"Enter the key ";
   cin>>key;

   bool found = search(num,50,key);
   if(found){
    cout<<"Key is found";
   }
   else
    cout<<"Key not found";

   return 0;
}
