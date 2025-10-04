class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<int> ans;
        vector<int> InDeg(V,0);
        
        for(int i=0; i<V; i++){
            for(int j=0; j<adj[i].size(); j++){
                InDeg[adj[i][j]]++;
            }
        }
        
        // push all the node of zero indegree into queue
        queue<int>q;
        
        for(int i=0; i<V; i++){
            if(InDeg[i] == 0){
              q.push(i);  
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int i=0; i<adj[node].size(); i++){
                InDeg[adj[node][i]]--;
                
                if(InDeg[adj[node][i]]==0){
                    q.push(adj[node][i]);
                }
            }
        }
        return ans;
        
    }
};