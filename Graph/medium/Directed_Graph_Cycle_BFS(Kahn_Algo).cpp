class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<int>InDeg(V,0);
        
        for(int i=0; i<V; i++){
            for(int j=0; j<adj[i].size(); j++){
                InDeg[adj[i][j]]++;
            }
        }
        
        queue<int> q;
        
        for(int i=0; i<V; i++){
            if(InDeg[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int i=0; i<adj[node].size(); i++){
                InDeg[adj[node][i]]--;
                if(InDeg[adj[node][i]] == 0){
                    q.push(adj[node][i]);
                }
            }
            
        }
        int count = ans.size();
        if(count != V){
            return 1;
        }
        return 0;
    }
};