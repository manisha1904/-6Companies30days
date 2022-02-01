long long power(int N,int R)
    {
       //Your code here
       if(N==0)
       return 0;
       if(R==0)
       return 1;
       long long ans;
       if(R&1){
           ans=N%mod;
           ans=(ans*power(N,R-1)%mod)%mod;
       }
       else{
           ans=power(N,R/2)%mod;
           ans=(ans*ans)%mod;
       }
       return (ans+mod)%mod;
        
    }
