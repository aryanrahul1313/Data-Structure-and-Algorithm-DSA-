class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> vec;
        for(int i=0; i<m; i++){
            vec.push_back(nums1[i]);
        }

        for(int i=0; i<n; i++){
            vec.push_back(nums2[i]);
        }

        sort(vec.begin(), vec.end());

        int mid = vec.size()/2;
        double ans = 0;

        if(vec.size() & 1){
            ans = vec[mid];
        }
        else{
            double ans1 = vec[mid];
            double ans2 = vec[mid-1];
            ans = (ans1+ans2)/2;
        }
        return ans;
    }
};
