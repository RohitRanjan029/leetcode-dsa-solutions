class Solution {
  public:
  
    void DFS(int node,vector<pair<int,int>>adj[],stack<int>&s,vector<bool>&visited){
        visited[node] = 1;
    
        for(int i=0; i<adj[node].size(); i++){
            if(visited[adj[node][i].first]!=1){
                DFS(adj[node][i].first,adj,s,visited);
            }
        }
        s.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        // create adj
        vector<pair<int,int>>adj[V];
        
        // for(int i=0; i<E; i++){
        //     int u = adj[i][0];
        //     int v = adj[i][1];
        //     int w = adj[i][2];
        //     adj[u].push_back(make_pair(v,w));
        // }ol
        for(auto &edge : edges){
            adj[edge[0]].push_back(make_pair(edge[1],edge[2]));
        }
        // topological sort(DFS)
        stack<int>s;
        vector<bool>visited(V,0);
        DFS(0,adj,s,visited);
        // empty the stack
        vector<int>dist(V,INT_MAX);
        dist[0] = 0;
        
        while(!s.empty()){
            int node = s.top();
            s.pop();
            for(int i=0; i<adj[node].size(); i++){
                int neighbour = adj[node][i].first;
                int weight = adj[node][i].second;
                dist[neighbour] = min(dist[neighbour],weight+dist[node]);
            }
        }
        for(int i=0; i<V; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        return dist;
    }
};