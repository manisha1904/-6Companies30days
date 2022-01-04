int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int ans=0;
        long long  prod=1;
        for(int start=0,end=0;end<n;end++){
            prod*=a[end];
            while(start<end && prod>=k)
                prod/=a[start++];
            if(prod<k){
                ans+=(end-start+1);
            }
        }
        return ans;
        
    }
