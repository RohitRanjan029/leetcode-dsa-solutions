class Solution {
  public:
  
    int r;
    int c;
  
    bool valid(int i,int j){
        return i>=0 && i<r && j>=0 && j<c;
    }
    int helpaterp(vector<vector<int>> hospital) {
        // code here
        r = hospital.size();
        c = hospital[0].size();
        
        
        queue<pair<int,int>> q;
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(hospital[i][j] == 2){
                    q.push(make_pair(i,j));
                }
            }
        }
        
        int timer = 0;
        while(!q.empty()){
            timer++;
            int current_pat = q.size();
            while(current_pat--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                int row[4] = {-1,1,0,0};
                int col[4] = {0,0,-1,1};
                
                for(int k=0; k<4; k++){
                    if(valid(i+row[k],j+col[k]) && hospital[i+row[k]][j+col[k]] == 1){
                        hospital[i+row[k]][j+col[k]] = 2;
                        q.push(make_pair(i+row[k],j+col[k]));
                    }
                }
                
                // // UP
                // if(hospital[i-1][j] == 1){
                    
                // }
                // // Down
                // if(hospital[i+1][j] == 1){
                    
                // }
                // // left
                // if(hospital[i][j-1] == 1){
                    
                // }
                // // right
                // if(hospital[i][j+1] == 1){
                    
                // }
            }
        }
        bool anyInfected = false;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(hospital[i][j] == 1){
                    return -1;
                }
                if(hospital[i][j] == 2) anyInfected = true;
            }
        }
        // pecial case: all 0
        if(!anyInfected) return 0;
        return timer-1;
    }
};