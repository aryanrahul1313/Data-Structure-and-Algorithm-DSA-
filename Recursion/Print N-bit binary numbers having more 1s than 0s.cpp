class Solution{
    private:
    void solve(int ones, int zeros, int N, string output, vector<string> &ans)
    {
        //base case
        if(N == 0){
            ans.push_back(output);
            return;
        }
        
        string opt1 = output;
        opt1.push_back('1');
        solve(ones+1, zeros, N-1, opt1, ans);
        
        if(ones > zeros){
            string opt2 = output;
            opt2.push_back('0');
            solve(ones, zeros+1, N-1, opt2, ans);
        }
    }

    public:	
    	vector<string> NBitBinary(int N)
    	{
    	    vector<string> ans;
    	    int ones = 0;
    	    int zeros = 0;
    	    string output = "";
    	    
    	    solve(ones, zeros, N, output, ans);
    	    return ans;
    	}
};
