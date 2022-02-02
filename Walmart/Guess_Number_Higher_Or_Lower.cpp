int dp[201][201];
    int solve(int start,int end){
        if(start>=end)
            return 0;
        if(dp[start][end]!=-1)
            return dp[start][end];
        int min_cost=INT_MAX;
        for(int i=start;i<=end;i++){
            min_cost=min(min_cost,i+max(solve(start,i-1),solve(i+1,end)));
        }
        return dp[start][end]=min_cost;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(1,n);
        
        
    }
