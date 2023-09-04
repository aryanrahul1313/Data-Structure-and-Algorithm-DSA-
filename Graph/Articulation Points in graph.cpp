//User function Template for C++

class Solution {
  private:
    void dfs(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &visited,
                vector<int> adj[], vector<int> &ap, int timer){
                    
        visited[node] = true;
        disc[node] = low[node] = timer++;
        int child = 0;
        
        for(auto nbr : adj[node]){
            if(nbr == parent){
                continue;
            }
            
            if(!visited[nbr]){
                dfs(nbr, node, disc, low, visited, adj, ap, timer);
                low[node] = min(low[node], low[nbr]);
                
                //check articulation point or not
                if(low[nbr] >= disc[node] && parent != -1){
                    ap[node] = true;
                }
                child++;
            }
            else{
                //back edge
                low[node] = min(low[node], disc[nbr]);         
            }
        }
        
        if(parent == -1 && child > 1){
            ap[node] = true;
        }
    }
  
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        
        int timer = 0;
        vector<int> disc(V);
        vector<int> low(V);
        vector<int> ap(V,0);
        unordered_map<int, bool> visited;
        
        for(int i=0; i<V; i++){
            disc[i] = -1;
            low[i] = -1;
        }
        
        //dfs
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(i, -1, disc, low, visited, adj, ap, timer);
            }
        }
        
        vector<int> result;
        for(int i=0; i<V; i++){
            if(ap[i] == 1){
                result.push_back(i);
            }
        }
        
        if(result.size() == 0){
            return {-1};
        }
        else{
            return result;
        }
    }
};
