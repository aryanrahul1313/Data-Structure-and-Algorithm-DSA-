class Solution{
    public:
    int maxIndexDiff(int A[], int N) 
    { 
        vector<int> left(N);
        vector<int> right(N);
        
        int mini = A[0];
        for(int i=0; i<N; i++){
            mini = min(mini, A[i]);
            left[i] = mini;
        }
        
        int maxi = A[N-1];
        for(int i=N-1; i>=0; i--){
            maxi = max(maxi, A[i]);
            right[i] = maxi;
        }
        
        
        int l = 0, r = 0;
        int ans = -1;
        while(l<N && r<N){
            if(left[l] <= right[r]){
                ans = max(ans,r-l);
                r++;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};
