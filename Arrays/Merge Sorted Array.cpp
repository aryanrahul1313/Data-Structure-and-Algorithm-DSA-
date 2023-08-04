class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> arr(m+n);
        int i=0, j=0, k=0;
        while(i<m && j<n){
            if(nums1[i] < nums2[j]){
                arr[k++] = nums1[i++];
            }
            else{
                arr[k++] = nums2[j++];
            }
            while(i<n){
                arr[k++] = nums1[i++];
            }
            while(j<m){
                arr[k++] = nums2[j++];
            }
        }
    }
}
