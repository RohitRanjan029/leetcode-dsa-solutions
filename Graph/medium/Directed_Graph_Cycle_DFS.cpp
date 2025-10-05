class Solution {
  public:
    bool DitectCycle(int node, vector<vector<int>> &adj,vector<bool> &visited,vector<bool> &path){
        path[node] = 1;
        visited[node] = 1;
        
        for(int i=0; i<adj[node].size(); i++){
            if(path[adj[node][i]]){
                return 1;
            }
            if(DitectCycle(adj[node][i],adj,visited,path)){
                return 1;
            }
        }
        path[node] = 0;
        return 0;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V,0);
        vector<bool> path(V,0);
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
               if(DitectCycle(i,adj,visited,path)){
                   return 1;
               }
            }
        }
        return 0;
        
    }
};