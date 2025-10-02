class Solution {
  public:
    bool  CycleDetect(int node, int parent, vector<int>adj[], vector<int>& visited){
        visited[node] = 1;
        for(int i=0; i<adj[node].size(); i++){
            if(parent == adj[node][i]){
                continue;
            }
            if(visited[adj[node][i]]){
                return 1;
            }
            if(CycleDetect(adj[node][i],node,adj, visited)){
                return 1;
            }
        }
        return 0;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(V,0);
        
       for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (CycleDetect(i, -1, adj, visited)) return 1;
            }
        }
        return 0;
    }
};