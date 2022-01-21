int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++)
	    sum+=arr[i];
	    bool dp[n+1][sum+1];
	    for(int i=0;i<=n;i++)
	        dp[i][0]=true;
	   for(int j=1;j<=sum;j++)
	   dp[0][j]=false;
	   for(int i=1;i<=n;i++){
	       for(int j=1;j<=sum;j++){
	           dp[i][j]=dp[i-1][j];
	           if(arr[i-1]<=j)
	           dp[i][j] |=dp[i-1][j-arr[i-1]];
	       }
	   }
	   
	   int ans=INT_MAX;
	   for(int j=sum/2;j>=0;j--){
	       if(dp[n][j]==true){
	           ans=sum-(2*j);
	           break;
	       }
	   }
	   return ans;
	   
	}
