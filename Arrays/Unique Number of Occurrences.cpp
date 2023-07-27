class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        vector<int> num;
        sort(arr.begin(),arr.end());
        int i = 0;
        while(i < n){
            int count = 1;
            for(int j=i+1;j<n;j++){
                if(arr[i]==arr[j]){
                    count = count + 1;
                }
                else{
                    break;
                }
            }
            num.push_back(count);
            i = i + count;
        }

        int len  = num.size();
        sort(num.begin(),num.end());
        for(int i=0;i<len-1;i++){
            if(num[i]==num[i+1]){
                return false;
            }
        }
        return true;
    }
};
