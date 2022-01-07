bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]%k]++;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]%k==0){
                if(m[nums[i]%k]%2==0)
                continue;
                else
                return false;
            }
            if(m[nums[i]%k]!=m[k-(nums[i]%k)])
            return false;
        }
        return true;
        
    }
