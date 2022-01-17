int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)
        sum+=arr[i];
        if(sum%2!=0)
        return false;
        bool dp[N+1][sum/2+1];
        for(int i=0;i<=N;i++){
            dp[i][0]=true;
        }
        for(int j=1;j<=sum/2;j++)
        dp[0][j]=false;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=sum/2;j++){
                if(arr[i-1]>j)
                dp[i][j]=dp[i-1][j];
                else{
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
                }
                
            }
        }
        return dp[N][sum/2];
    }
