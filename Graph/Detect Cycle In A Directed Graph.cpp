#include<bits/stdc++.h>

int detectCycleInDirectedGraph(int n, vector <pair<int, int>> &edges)
{
    // create adjacency list
    unordered_map<int, list<int>> adj;

    for(int i=0; i<edges.size(); i++){
      int u = edges[i].first - 1;
      int v = edges[i].second - 1;
      adj[u].push_back(v); 
    }

    // find all indegrees
    vector<int> indegree(n);
    for(auto i : adj){
      for(auto j : i.second){
        indegree[j]++;
      }
    }

    // 0 indegree walo ko push krdo
    queue<int> q;
    for( int i=0; i<n; i++){
      if(indegree[i] == 0){
        q.push(i);
      }
    }

    // do BFS 
    int cnt = 0;
    while(!q.empty()){
      int front = q.front();
      q.pop();

      cnt++;

      //neighbour indegree update
      for(auto neighbour : adj[front]){
        indegree[neighbour]--;
        if(indegree[neighbour] == 0){
          q.push(neighbour);
        }
      }
    }

    if(cnt == n){
      return false;
    }
    else{
      return true;
    }
}
