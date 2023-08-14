//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        
        stack<int> s;
        int n = q.size();
        
        for(int i=0; i<n/2; i++){
            int val = q.front();
            q.pop();
            s.push(val);
        }
        
        for(int i=0; i<n/2; i++){
            int val = s.top();
            s.pop();
            q.push(val);
        }
        
        for(int i=0; i<n/2; i++){
            int val = q.front();
            q.pop();
            q.push(val);
        }
        
        for(int i=0; i<n/2; i++){
            int val = q.front();
            q.pop();
            s.push(val);
        }
        while(!s.empty()){
            int val = s.top();
            s.pop();
            q.push(val);
            
            int element = q.front();
            q.pop();
            q.push(element);
        }
        
        vector<int> ans;
        while(!q.empty()){
            int val = q.front();
            q.pop();    
            ans.push_back(val);
        }
        
        return ans;
    }
};
