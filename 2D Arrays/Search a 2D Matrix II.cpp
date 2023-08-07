class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();

        int r_index = 0;
        int c_index = c - 1;
        //we will start from corner element i.e. 15
        while(r_index<r && c_index>=0){
            int element = matrix[r_index][c_index];
            if(element == target){
                return 1;
            }
            if(element < target){
                r_index++;
            }
            else{
                c_index--;
            }
        }
        return 0;
    }
};
