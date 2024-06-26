#include<bits/stdc++.h>

void DFS(unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj,
            vector<int> &component, int node){

    component.push_back(node);
    visited[node] = true;

    //recursive call for all connected node
    for(auto i:adj[node]){
        if(!visited[i]){
            DFS(visited, adj, component, i);
        }
    }     
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    //prepare adjacency list
    unordered_map<int, list<int>> adj;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> component;
            DFS(visited, adj, component, i);
            ans.push_back(component);
        }
    }
    return ans;
}
