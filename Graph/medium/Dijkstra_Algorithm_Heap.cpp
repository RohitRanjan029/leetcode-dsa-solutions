// User Function Template
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
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>p;
        p.push({0,src});
        
        // select a node which is not explored yet and its distance value is minimum
        
            
        while(!p.empty()){
           int node = p.top().second;
           p.pop();
           
           if(explore[node] == 1){
               continue;
           }
           explore[node] = 1;
           
            for(int i=0; i<adj[node].size(); i++){
            int neighbour = adj[node][i].first;
            int weight = adj[node][i].second;
            if(!explore[neighbour] && (dist[node]+weight<dist[neighbour])){
                dist[neighbour] = dist[node]+weight;
                p.push({dist[neighbour],neighbour});
            }
        }
           
       }
        
        return dist;
        
    }
};