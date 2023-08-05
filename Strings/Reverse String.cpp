class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int l = s.size();
        int i=0, j=l-1;
        while(i <= j){
            swap(s[i++], s[j--]);
        }
    }
}
