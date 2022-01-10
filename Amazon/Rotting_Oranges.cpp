int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        if(grid.empty())
            return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    q.push({{i,j},0});
            }
        }
        int ans=0;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int i=x.first.first;
            int j=x.first.second;
            int time=x.second;
            ans=max(ans,time);
            if(i>0 && grid[i-1][j]==1){
                grid[i-1][j]=2;
                q.push({{i-1,j},time+1});
        }
            if(i<grid.size()-1 && grid[i+1][j]==1){
                grid[i+1][j]=2;
                q.push({{i+1,j},time+1});
            }
            if(j>0 && grid[i][j-1]==1){
                grid[i][j-1]=2;
                q.push({{i,j-1},time+1});
            }
            if(j<grid[0].size()-1 && grid[i][j+1]==1){
                grid[i][j+1]=2;
                q.push({{i,j+1},time+1});
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return ans;
        
        
    }
