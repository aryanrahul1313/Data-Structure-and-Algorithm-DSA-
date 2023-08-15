// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    
    // Step 1: Fetch first k elements from q and put into stack
    stack<int> s;
    
    for(int i=0; i<k; i++){
        int val = q.front();
        q.pop();
        s.push(val);
    }
    
    // Step 2: fetch from stack and push into q
    while(!s.empty()){
        int val = s.top();
        s.pop();
        q.push(val);
    }
    
    // Step 3: fetch first (n-k) elements from q and push back
    int t = q.size() - k;
    
    while(t--){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}
