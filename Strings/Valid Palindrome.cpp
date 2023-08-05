class Solution {
public:
    char check(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }
    else{
        return (ch-'A'+'a');
    }
}

bool valid(char ch){
    if((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z') || (ch>='0'&&ch<='9')){
        return 1;
    }
    else{
        return 0;
    }
}

bool isPalindrome(string s)
{
    int i=0, j=s.length() - 1;
    while(i <= j){
        if(valid(s[i])){
            if(valid(s[j])){
                if(tolower(s[i]) != tolower(s[j])){
                    return false;
                }
                else{
                    i++;
                    j--;
                }
            }
            else{
                j--;
            }
        }
        else{
            i++;
        }
    }
    return true; 
}
};
