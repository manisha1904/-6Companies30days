int maxProfit(int k, int N, int A[]) {
        // code here
        int t[k+1][N+1];
        for(int i=0;i<=k;i++){
            t[i][0]=0;
        }
        for(int j=0;j<=N;j++){
            t[0][j]=0;
        }
        for(int i=1;i<=k;i++){
            int prev=INT_MIN;
            for(int j=1;j<N;j++){
                prev=max(prev,t[i-1][j-1]-A[j-1]);
                t[i][j]=max(t[i][j-1],prev+A[j]);
            }
        }
        return t[k][N-1];
    }
