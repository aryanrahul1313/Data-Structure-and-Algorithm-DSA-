class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 && k==1){
            return 0;
        }

        int mid = pow(2,n-1)/2;

        if(k <= mid){
            //k lies in left half
            return kthGrammar(n-1, k);
        }
        else{
            //k lies in right half
            return !kthGrammar(n-1, k-mid);
        }
    }
};
