class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int>>adj[V];
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[v].push_back({u,w});
            adj[u].push_back({v,w});
        }
        
        vector<int>explore(V,0);
        vector<int>dist(V,INT_MAX);
        dist[src] = 0;
        
        // select a node which is not explored yet and its distance value is minimum
        int count = V;
        while(count--){
            
        int node = -1;
        int value = INT_MAX;
        for(int i=0; i<V; i++){
            if(explore[i]!=1 && value>dist[i]){
                node = i;
                value = dist[i];
            }
        }
        explore[node] = 1;
        
        for(int i=0; i<adj[node].size(); i++){
            int neighbour = adj[node][i].first;
            int weight = adj[node][i].second;
            if(!explore[neighbour] && (dist[node]+weight<dist[neighbour])){
                dist[neighbour] = dist[node]+weight;
            }
        }
        }
        
        return dist;
        
    }
};