#include <bits/stdc++.h> 
bool valid(char ch){
    if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
        return 1;
    }
    return 0;
}

char toLower(char ch){
    if(ch>='A' && ch<='Z'){
        return ch-'A'+'a';
    }
    return ch;
}

bool isPalindrome(string s){
    int i=0, j=s.length() - 1;
    while(i <= j){
        if(s[i] != s[j]){
            return 0;
        }
        else{
            i++;
            j--;
        }
    }
    return 1;
}

bool checkPalindrome(string s) {
    string temp = "";
    for(int i=0;i<s.length();i++){  //non-alphanumric removed
        if(valid(s[i])){
            temp.push_back(s[i]);
        }
    }

    for(int j=0;j<temp.length();j++){   //lower case
        temp[j] = toLower(temp[j]);
    }
    return isPalindrome(temp);
}

