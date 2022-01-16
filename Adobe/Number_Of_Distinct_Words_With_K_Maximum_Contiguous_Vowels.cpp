long long int power(long long int x,long long int y,long long int p){
      long long int res=1ll;
      x=x%p;
      if(x==0)
      return 0;
      while(y){
          if(y&1)
          res=(res*x)%p;
          y=y>>1;
          x=(x*x)%p;
          }
      return res;
  }
    int kvowelwords(int N, int K) {
        // Write Your Code here
        long long int dp[N+1][K+1]={0};
        long long int MOD=1000000007;
        long long int ans=1;
        //memset(dp,0,sizeof(dp));
        for(long long int i=1;i<=N;i++)
        {
            dp[i][0]=ans*21;
            dp[i][0]%=MOD;
            ans=dp[i][0];
            
            for(long long int j=1;j<=K;j++){
                if(j>i){
                    dp[i][j]=0;
                }
                else if(i==j){
                    dp[i][j]=power(5ll,i,MOD);
                }
                else if(i>j){
                    dp[i][j]=dp[i-1][j-1]*5;
                }
                dp[i][j]%=MOD;
                ans+=dp[i][j];
                ans%=MOD;
                
            }
        }
        
       
        return ans;
    }
