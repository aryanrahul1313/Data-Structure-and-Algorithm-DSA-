#include <bits/stdc++.h> 
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for(int i=0;i<mCols;i++){
        if(i & 1){    //bottom to top // odd index
            for(int b=nRows-1;b>=0;b--){
                ans.push_back(arr[b][i]);
            }
        }
        else{       //top to bottom  //0 or even index
            for(int a=0;a<nRows;a++){
                ans.push_back(arr[a][i]);
            }
        }
    }
    return ans;
}
