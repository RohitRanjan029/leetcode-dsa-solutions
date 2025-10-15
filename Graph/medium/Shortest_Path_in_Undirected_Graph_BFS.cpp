class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int N = adj.size();
        vector<int>dist(N,-1);
        vector<bool>visited(N,0);
        
        queue<int>q;
        q.push(src);
        dist[src] = 0;
        visited[src] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0; i<adj[node].size(); i++){
                if(visited[adj[node][i]] != 1){
                    q.push(adj[node][i]);
                    dist[adj[node][i]] = dist[node]+1;
                    visited[adj[node][i]] = 1;
                    
                }
                
            }
        }
        return dist;
    }
};