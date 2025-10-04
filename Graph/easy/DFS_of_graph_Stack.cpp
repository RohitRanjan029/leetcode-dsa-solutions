class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> ans;
        stack<int> q;
        vector<bool> visited(n,0);
        q.push(0);
        visited[0] = 1;
        while(!q.empty()){
            int node = q.top();
            q.pop();
            ans.push_back(node);
            for(int i=0; i<adj[node].size(); i++){
                if(!visited[adj[node][i]]){
                    visited[adj[node][i]] = 1;
                    q.push(adj[node][i]);
                }
            }
        }
        return ans;
    }
};