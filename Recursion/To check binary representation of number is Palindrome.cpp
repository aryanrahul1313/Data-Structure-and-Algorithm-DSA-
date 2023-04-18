#include <bits/stdc++.h> 
bool isPalindrome(string str,int i, int j){
    if(i>j)
        return true;

    if(str[i]!=str[j]){
        return false;
    }
    else{
        return isPalindrome(str,i+1,j-1);
    }
}
bool checkPalindrome(long long N)
{
	string str;
    while(N>0){
        str = str + to_string(N&1);
        N = N>>1;
    }
	
	return isPalindrome(str,0,str.length()-1);
	
}
