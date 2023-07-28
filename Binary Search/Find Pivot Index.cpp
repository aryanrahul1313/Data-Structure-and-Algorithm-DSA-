class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum = sum + nums[i];
        }
        int lsum = 0;
        int rsum = sum;
        while(s <= e){
            rsum = rsum - nums[s];
            if(lsum == rsum){
                return s;
            }
            lsum = lsum + nums[s];
            s++;
        }
        return -1;
    }
};
