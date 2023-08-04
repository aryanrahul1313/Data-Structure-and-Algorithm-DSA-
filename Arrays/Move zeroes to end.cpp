class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s = 0, i=0;
        while(i < nums.size()){
            if(nums[i] != 0){
                swap(nums[s++], nums[i++]);
            }
            else{
                i++;
            }
        }
        
    }
};
