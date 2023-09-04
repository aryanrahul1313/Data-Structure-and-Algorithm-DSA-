// User function Template for C++

class Solution {
  private:
    void dfs(vector<pair<int, int>> adj[], int node, stack<int> &s, int visited[]){
                    
        visited[node] = 1;  
        
        for(auto neighbour : adj[node]){
            int v = neighbour.first;
            if(!visited[v]){
                dfs(adj, v, s, visited);
            }
        }
        s.push(node);
    }
    
  public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges)
    {
        vector<pair<int, int>> adj[N];
        for(int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v, wt});
        }
        
        //topological sort
        int visited[N] = {0};
        stack<int> s;
        for(int i=0; i<N; i++){
            if(!visited[i]){
                dfs(adj, i, s, visited);
            }
        }
        
        vector<int> distance(N);
        
        for(int i=0; i<N; i++){
            distance[i] = 1e9;
        }
        
        distance[0] = 0;
        
        while(!s.empty()){
            int top = s.top();
            s.pop();
            
            for(auto it : adj[top]){
                int v = it.first;
                int wt = it.second;
                
                if(distance[top] + wt < distance[v]){
                    distance[v] = distance[top] + wt;
                } 
            }
        }
        for(int i=0; i<N; i++)
        {
            if(distance[i] == 1e9)
            {
                distance[i] = -1;
            }
        }
        return distance;
    }
};
