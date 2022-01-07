int longestMountain(vector<int>& arr) {
        int ans=0;
        for(int i=1;i<arr.size()-1;i++){
            int j=i;
            int left=0,right=0;
            while(j>=1 && arr[j]>arr[j-1]){
                left++;
                j--;
            }
            j=i;
            while(j<arr.size()-1 && arr[j]>arr[j+1]){
                right++;
                j++;
            }
            if(left==0 || right==0)
                continue;
            ans=max(ans,left+right+1);
            
        }
        return ans;
        
    }
