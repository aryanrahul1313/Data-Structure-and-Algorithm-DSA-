class Solution {
    private:
        void solve(vector<int> &arr, int index, int k, int &ans)
        {
            //basae case
            if(arr.size() == 1){
                ans = arr[0];
                return;
            }
            //person going to get killed is index
            index = (index + k) % arr.size();
            arr.erase(arr.begin() + index);
            
            solve(arr, index, k, ans);
        }
        
    public:
        int safePos(int n, int k) {
            vector<int> arr;
            for(int i=0; i<n; i++){
                arr.push_back(i+1);
            }
            
            int ans = -1;
            k = k-1; //watch aditya verma LOL!
            
            solve(arr, 0, k, ans);
            return ans;
        }
    };
