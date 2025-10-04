class Solution {
  public:
    void DFS(int node, vector<vector<int>>& adj, vector<int>&ans, vector<bool> &visited){
        visited[node] = 1;
        ans.push_back(node);
        for(int i=0; i<adj[node].size(); i++){
            if(!visited[adj[node][i]]){
                DFS(adj[node][i],adj,ans,visited);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool> visited(n,0);
        vector<int> ans;
        DFS(0,adj,ans,visited);
        
        return ans;
        
    }
};