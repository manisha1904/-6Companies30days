int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        int trailingZero[n];
        memset(trailingZero,0,sizeof(trailingZero));
        int ans=0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0)
                    count++;
                else
                    break;
            }
            trailingZero[i]=count;
        }
        for(int i=0;i<n;i++){
            if(trailingZero[i]<(n-i-1)){
                cout<<i<<"  ";
                int j=i+1;
                while(j<n && trailingZero[j]<(n-i-1)){
                   // cout<<trailingZero[j]<<"  ";
                    j++;
                }
                    
                if(j==n)
                    return -1;
                while(j>i){
                    swap(trailingZero[j-1],trailingZero[j]);
                    j--;
                    ans++;
                }
            }
            
        }
        return ans;
        
    }
