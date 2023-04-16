int solve(int arr[],int s,int e,int key){
    if(s>e)
        return -1;

    int mid = s + (e-s)/2;

    if(arr[mid]==key)
        return mid;

    if(arr[mid]<key){
        return solve(arr,mid+1,e,key);
    }
    else{
        return solve(arr,s,mid-1,key);
    }
}

int binarySearch(int *input, int n, int val)
{
    int ans = solve(input,0,n-1,val);
    return ans;
}
