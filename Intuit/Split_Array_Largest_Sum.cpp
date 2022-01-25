//DP solution -- TLE
   /* int dp[1002][1002];
    int solve(vector<int>prefix,int cur_index,int m){
        int n=prefix.size()-1;
        if(dp[cur_index][m]!=-1)
            return dp[cur_index][m];
        if(m==1)
            return dp[cur_index][m]=prefix[n]-prefix[cur_index];
        int ans=INT_MAX;
        for(int i=cur_index;i<=n-m;i++){
            int first_sum=prefix[i+1]-prefix[cur_index];
            int largest_sum=max(first_sum,solve(prefix,i+1,m-1));
            ans=min(ans,largest_sum);
            if(first_sum>=ans)
                break;
        }
        return dp[cur_index][m]=ans;
    }*/
    int splitArray(vector<int>& nums, int m) {
        //memset(dp,-1,sizeof(dp));
        //vector<int>prefix(nums.size()+1,0);
        //for(int i=0;i<nums.size();i++){
          //  prefix[i+1]=prefix[i]+nums[i];
        //}
        //return solve(prefix,0,m);
        
        int start=0,end=0;
        for(int i=0;i<nums.size();i++){
            start=max(start,nums[i]);
            end+=nums[i];
        }
        while(start<=end){
            int mid=(start+end)/2;
            int i=0;
            int count=m;
            while(count){
                int temp=0;
                while(i<nums.size()){
                    temp+=nums[i];
                    if(temp>mid){
                        cout<<temp<<"  "<<mid<<endl;
                        break;
                    }
                    i++;
                }
                if(i==nums.size())
                    break;
                count--;
            }
            if(count>=0 && i==nums.size())
                end=mid-1;
            else
                start=mid+1;
        }
        return start;
    }
