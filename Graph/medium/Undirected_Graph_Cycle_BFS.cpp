class Solution {
  public:
  
    bool BFS(int vertex,vector<int>adj[], vector<bool>&visited){
        queue<pair<int,int>> q;
        visited[vertex] = 1;
        q.push(make_pair(vertex,-1)); // node , parent
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int i=0; i<adj[node].size(); i++){
                if(adj[node][i] == parent){
                    continue;
                }
                if(visited[adj[node][i]]){
                    return 1;
                }
                visited[adj[node][i]] = 1;
                q.push(make_pair(adj[node][i],node));
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
        vector<bool> visited(V,0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (BFS(i,adj, visited)) return 1;
            }
        }
        return 0;
    }
};