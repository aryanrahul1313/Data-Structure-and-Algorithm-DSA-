class Solution {
private:
    void solve(string input, string output, vector<string> &ans){
        //base case
        if(input.length() == 0){
            ans.push_back(output);
            return;
        }

        if(isalpha(input[0])){ // to check for alphabets
            string opt1 = output;
            string opt2 = output;

            opt1.push_back(tolower(input[0]));
            opt2.push_back(toupper(input[0]));

            input.erase(input.begin() + 0);

            solve(input, opt1, ans);
            solve(input, opt2, ans);
        }
        else{ // it is a digit not alphabet
            string opt = output;
            opt.push_back(input[0]);
            input.erase(input.begin() + 0);
            solve(input, opt, ans);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        string input = s;
        string output = "";
        vector<string> ans;

        solve(input, output, ans);
        return ans;
    }
};
