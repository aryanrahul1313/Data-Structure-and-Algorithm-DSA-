//User function template for C++

class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int a, int b, int n){
        if(M[a][b] == 1){
            return true;
        }
        else{
            return false;
        }
    } 
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        // step 1:
        for(int i = 0; i<n; i++){
            s.push(i);
        }
        
        // step 2: get two elements and compare it
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b,n)){
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        
        // single element in stack is potential celebrity
        // so verify it
        
        // row check
        int candidate = s.top();
        int zeroCount = 0;
        
        for(int i=0; i<n; i++){
            if(M[candidate][i] == 0){
                zeroCount++;
            }
        }
        // all zeroes
        if(zeroCount != n){
            return -1;
        }
        
        // column check
        int oneCount = 0;
        
        for(int i=0; i<n; i++){
            if(M[i][candidate] == 1){
                oneCount++;
            }
        }
        // all ones
        if(oneCount != n-1){
            return -1;
        }
        
        return candidate;
    }
};
