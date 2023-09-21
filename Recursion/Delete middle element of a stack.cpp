class Solution
{
    private:
    void solve(stack<int>&s, int k){
        if(k == 1){
            s.pop();
            return;
        }
        
        int val1 = s.top();
        s.pop();
        solve(s, k-1);
        s.push(val1);
    }
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int k = sizeOfStack/2 +1;
        solve(s, k);
    }
};
