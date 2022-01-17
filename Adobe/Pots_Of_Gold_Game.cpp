int dp[1002][1002];
int solve(vector<int>v,int start,int end){
    if(start>end)
    return 0;
    if(dp[start][end]!=-1)
    return dp[start][end];
    int s=v[start]+min(solve(v,start+2,end),solve(v,start+1,end-1));
    int e=v[end]+min(solve(v,start+1,end-1),solve(v,start,end-2));
    return dp[start][end]=max(s,e);
    
}
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    memset(dp,-1,sizeof(dp));
	    return solve(A,0,n-1);
    }
