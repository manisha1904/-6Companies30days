int findPosition(int N , int M , int K) {
        // code here
        if(N-K+1>=M)
        return M+K-1;
        M-=(N-K+1);
        return (M%N==0?N:M%N);
    }
