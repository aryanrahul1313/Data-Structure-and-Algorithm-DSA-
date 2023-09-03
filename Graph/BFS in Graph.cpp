vector<int> bfsTraversal(int n, vector<vector<int>>& adj) {
    vector<int> result;
    vector<bool> visited(n, false);
    queue<int> q;

    // Start BFS from node 0
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();
        
        result.push_back(frontNode);

        for (int i : adj[frontNode]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    return result;
}
