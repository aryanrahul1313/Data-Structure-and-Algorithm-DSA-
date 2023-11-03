class Solution{
public:
	int print2largest(int arr[], int n) 
	{
	    sort(arr, arr+n);
	    int ans = -1;
	    int temp = arr[n-1];
	    for(int i=n-2; i>=0; i--){
	        if(arr[i] == temp){
	            continue;
	        }
	        else{
	            ans = arr[i];
	            break;
	        }
	    }
	    return ans;
	}
};
