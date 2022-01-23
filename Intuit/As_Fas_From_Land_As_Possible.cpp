 int maxDistance(vector<vector<int>>& grid) {
        int max=0;
        int n=0;
        queue<pair<int,int>>q;
        vector<pair<int,int>>v1;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0){
                   q.push({i,j});
                }
                else{
                  v1.push_back({i,j});
                }
            }
        }
        if(q.empty() || v1.empty())
            return -1;
        while(!q.empty()){
            int u=q.front().first;
            int v=q.front().second;
            q.pop();
            int i=0;
            int distance=200;
            for(auto i:v1){
                int x=i.first;
                int y=i.second;
             distance=min(distance,abs(u-x)+abs(v-y));
                if(distance==1)
                    break;
            }
            if(distance>max)
                max=distance;
            
        }
        
        return max;
        
    }
