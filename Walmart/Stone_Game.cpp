 int dp[502][502];
    int solve(vector<int>&piles,int start,int end){
        if(start>end)
            return 0;
        if(dp[start][end]!=-1)
            return dp[start][end];
        int op1=piles[start]+min(solve(piles,start+2,end),solve(piles,start+1,end-1));
        int op2=piles[end]+min(solve(piles,start+1,end-1),solve(piles,start,end-2));
        return dp[start][end]=max(op1,op2);
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int temp=solve(piles,0,piles.size()-1);
        cout<<temp;
        int sum=0;
        for(int i=0;i<piles.size();i++)
            sum+=piles[i];
        return temp>(sum-temp);
        
    }
