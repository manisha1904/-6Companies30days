int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int dp[n];
        memset(dp,0,sizeof(n));
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-2]+arr[i],dp[i-1]);
        }
        return dp[n-1];
    }
