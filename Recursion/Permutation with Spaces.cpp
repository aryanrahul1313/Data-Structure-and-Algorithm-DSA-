class Solution{
private:
    void solve(string S, string opt, vector<string> &ans)
    {
        //base case
        if(S.length() == 0){
            ans.push_back(opt);
            return;
        }
        
        string opt1 = opt;
        string opt2 = opt;
        
        //letter with space
        opt1.push_back(' ');
        opt1.push_back(S[0]);
        
        //letter without space
        opt2.push_back(S[0]);
        
        //remove )th letter
        S.erase(S.begin() + 0);
        
        //recursion call
        solve(S, opt1, ans);
        solve(S, opt2, ans);
    }
    
public:
    vector<string> permutation(string S){
        // Code Here
        string opt = "";
        opt.push_back(S[0]);
        S.erase(S.begin() + 0);
        
        vector<string> ans;
        solve(S, opt, ans);
        return ans;
    }
};
