class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        vector<int> adj[N];
        for(int i=0; i<P; i++){
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        vector<int>InDeg(N,0);
        
        queue<int>q;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<adj[i].size(); j++){
                InDeg[adj[i][j]]++;
            }
        }
        
        for(int i=0; i<N; i++){
            if(InDeg[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            
            for(int i=0; i<adj[node].size(); i++){
                InDeg[adj[node][i]]--;
                if(InDeg[adj[node][i]] == 0){
                    q.push(adj[node][i]);
                }
            }
        }
        return N == count;
    }
};