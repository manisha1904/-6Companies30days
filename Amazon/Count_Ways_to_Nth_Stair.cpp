long long count[1000000+2];
    long long solve(int m){
        if(m==0 || m==1)
        return m;
        if(count[m]!=-1)
        return count[m];
        int temp=max(solve(m-1),solve(m-2));
        if(m%2==0)
        count[m]=temp+1;
        else
        count[m]=temp;
        return count[m];
    }
    long long countWays(int m)
    {
        // your code here
        memset(count,-1,sizeof(count));
        count[0]=0;
        count[1]=1;
        count[2]=2;
        return solve(m);
        
    }
