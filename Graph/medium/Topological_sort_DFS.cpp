class Solution {
  public:
    void DFS(int node,vector<vector<int>> &adj,  stack<int>&s, vector<bool>&visited){
        visited[node] = 1;
        
        // look at its neighbour one by one
        for(int i=0; i<adj[node].size(); i++){
            if(!visited[adj[node][i]]){
                DFS(adj[node][i], adj, s,visited);
            }
        }
        s.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V,0);
        stack<int>s;
        for(int i=0; i<V; i++){
            if(!visited[i]){
               DFS(i,adj,s,visited); 
            }
        }
        
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};