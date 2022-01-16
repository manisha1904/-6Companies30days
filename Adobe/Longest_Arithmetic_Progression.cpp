int lengthOfLongestAP(int A[], int n) {
        if(n<=2)
        return n;
        // code here
        int dp[n][n];
        for(int i=0;i<n;i++)
        dp[i][n-1]=2;
        int ans=2;
        for(int j=n-2;j>=0;j--){
            int i=j-1;
            int k=j+1;
            while(i>=0 && k<n){
                if(A[i]+A[k]==2*A[j]){
                    dp[i][j]=dp[j][k]+1;
                    ans=max(ans,dp[i][j]);
                    //cout<<dp[j][k]<<"  ";
                    i--;
                    k++;
                }
                else if(A[i]+A[k]>2*A[j]){
                    dp[i][j]=2;
                    i--;
                }
                else
                    k++;
            }
            while(i>=0){
                dp[i][j]=2;
                i--;
            }
            
        }
        return ans;
    }
