vector<int>dr = {-1,1,0,0,1,1,-1,-1};
    vector<int>dc = {0,0,-1,1,1,-1,1,-1};
    //Function to find unit area of the largest region of 1s.
    bool isSafe(int row,int col,int n,int m){
        return (row<n && row>=0 && col>=0 && col<m);
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int ans=0;
         
        queue<pair<int,int>>q;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    grid[i][j]=0;
                    int count=1;
                    q.push({i,j});
                    while(!q.empty()){
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                    for(int k=0;k<8;k++){
                        int n_x=x+dr[k];
                        int n_y=y+dc[k];
                        if(isSafe(n_x,n_y,n,m) && grid[n_x][n_y]){
                            grid[n_x][n_y]=0;
                            q.push({n_x,n_y});
                            count++;
                        }
                        
                        
                    }
                    
                    }
                    ans=max(ans,count);
                }
            }
        }
        
        return ans;
    }
