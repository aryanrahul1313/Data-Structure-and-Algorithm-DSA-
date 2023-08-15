class Solution {
	public:
		string FirstNonRepeating(string A){
		    
		    unordered_map<char, int> count;
		    queue<int> q;
		    string ans = "";
		    
		    for(int i=0; i<A.length(); i++){
		        char ch = A[i];
		        
		        //increase count
		        count[ch]++;
		        
		        //queue me push kro
		        q.push(ch);
		        
		        while(!q.empty()){
		            if(count[q.front()] > 1){
		                q.pop();  // repeating character
		            }
		            else{
		                // non-repeating character milgya
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty()){
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

};
