class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        vector<int> ans;

        int count = 0;
        int total = r * c;
        //index initialisation  
        int sr = 0;    //starting row
        int sc = 0;    //starting col
        int er = r - 1;
        int ec = c - 1;

        while(count < total){
            //starting row
            for(int i=sc; i<=ec && count<total; i++){
                ans.push_back(matrix[sr][i]);
                count++;
            }
            sr++;
            //ending column
            for(int i=sr; i<=er && count<total; i++){
                ans.push_back(matrix[i][ec]);
                count++;
            }
            ec--;
            //ending row
            for(int i=ec; i>=sc && count<total; i--){
                ans.push_back(matrix[er][i]);
                count++;
            }
            er--;
            //starting column
            for(int i=er; i>=sr && count<total; i--){
                ans.push_back(matrix[i][sc]);
                count++;
            }
            sc++;
        }
        return ans;
    }
};
