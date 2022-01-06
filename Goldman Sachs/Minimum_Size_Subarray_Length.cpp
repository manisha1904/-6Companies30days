 int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,ans=INT_MAX;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>=target){
                ans=min(ans,i+1-l);
                sum-=nums[l++];
            }
        }
        return (ans!=INT_MAX?ans:0);
        
        
    }
