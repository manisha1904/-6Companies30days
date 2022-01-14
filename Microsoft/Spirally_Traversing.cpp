vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here
        vector<int>ans;
        int seen[r][c];
        memset(seen,false,sizeof(seen));
        int i=0,j=0,di=0;
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        for(int k=0;k<r*c;k++){
            ans.push_back(matrix[i][j]);
            seen[i][j]=true;
            int row=i+dr[di];
            int col=j+dc[di];
            if(row>=0 && col>=0 && row<r && col<c && !seen[row][col]){
                i=row;
                j=col;
            }
            else{
                di=(di+1)%4;
                i+=dr[di];
                j+=dc[di];
            }
            
        }
        
        return ans;
    }
