void merge(vector < int > & arr, int s, int e){
    int mid = (e+s)/2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];
    //copy values
    int mainIndex = s;
    for(int i=0;i<len1;i++){
        first[i] = arr[mainIndex++];
    }

    mainIndex = mid+1;
    for(int i=0;i<len2;i++){
        second[i] = arr[mainIndex++];
    }

    //merge two sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainIndex = s;

    while(index1<len1 && index2<len2){
        if(first[index1] < second[index2]){
            arr[mainIndex++] = first[index1++];
        }
        else{
            arr[mainIndex++] = second[index2++];
        }
    }

    while(index1<len1){
        arr[mainIndex++] = first[index1++];
    }

    while(index2<len2){
        arr[mainIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
}

void solve(vector < int > & arr, int s, int e){
    if(s>=e)
        return;

    int mid = (e+s)/2;

    //left part sort
    solve(arr,s,mid);

    //right part sort
    solve(arr,mid+1,e);

    //merge both part
    merge(arr,s,e);

}


void mergeSort(vector < int > & arr, int n) {
    solve(arr, 0, n-1);
}
