// n is the number of pairs of parentheses
class Solution
{
    private:
        void solve(int open, int close, string output, vector<string> &ans)
        {
            //base case
            if(open == 0 && close == 0){
                ans.push_back(output);
                return;
            }
            
            if(open != 0){
                string opt1 = output;
                //add opening paranthesis
                opt1.push_back('(');
                
                solve(open-1, close, opt1, ans);
            }
            
            if(close > open){
                string opt2 = output;
                //add closing paranthesis
                opt2.push_back(')');
                
                solve(open, close-1, opt2, ans);
            }
        }
    
    public:
        vector<string> AllParenthesis(int n) 
        {
            vector<string> ans;
            int close = n;
            int open = n;
            string output = "";
            
            solve(open, close, output, ans);
            return ans;
        }
};
