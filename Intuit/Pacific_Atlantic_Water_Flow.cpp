void solve(vector<vector<int>>&heights,int i,int j,int prev,vector<vector<bool>>&ocean){
        int m=heights.size(),n=heights[0].size();
        if(i<0 || j<0 || i>=m || j>=n || prev>heights[i][j])
            return;
        if(ocean[i][j])
            return;
        ocean[i][j]=true;
        solve(heights,i-1,j,heights[i][j],ocean);
        solve(heights,i+1,j,heights[i][j],ocean);
        solve(heights,i,j-1,heights[i][j],ocean);
        solve(heights,i,j+1,heights[i][j],ocean);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>pacific(m,vector<bool>(n,false));
        vector<vector<bool>>atlantic(m,vector<bool>(n,false));
        
        for(int i=0;i<m;i++){
            solve(heights,i,0,heights[i][0],atlantic);
            solve(heights,i,n-1,heights[i][n-1],pacific);
        }
        for(int j=0;j<n;j++){
            solve(heights,0,j,heights[0][j],atlantic);
            solve(heights,m-1,j,heights[m-1][j],pacific);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
