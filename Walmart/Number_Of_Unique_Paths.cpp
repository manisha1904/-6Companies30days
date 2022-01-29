int dp[20][20];
    int solve(int x,int y,int n,int m){
        if(x==n || y==m)
        return dp[x][y]=1;
        if(dp[x][y]!=-1)
        return dp[x][y];
        return dp[x][y]=solve(x+1,y,n,m)+solve(x,y+1,n,m);
    }
    int NumberOfPath(int a, int b)
    {
        //code here
        memset(dp,-1,sizeof(dp));
        return solve(0,0,a-1,b-1);
        //return dp[a-1][b-1];
    }
