vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-3;i++){
            if(arr[i]>0 && arr[i]>k)
            break;
            if(i>0 && arr[i]==arr[i-1])
            continue;
            for(int j=i+1;j<arr.size()-2;j++){
                if(j>i+1 && arr[j]==arr[j-1])
                continue;
                int l=j+1;
                int r=arr.size()-1;
                while(l<r){
                    int sum=arr[l]+arr[r]+arr[i]+arr[j];
                    int old_l=l;
                    int old_r=r;
                    if(sum==k){
                        ans.push_back({arr[i],arr[j],arr[l],arr[r]});
                        while(l<r && arr[l]==arr[old_l])
                        l++;
                        while(l<r && arr[r]==arr[old_r])
                        r--;
                    }
                    else if(sum<k)
                        l++;
                    else
                        r--;
                }
                
                
            }
        }
        return  ans;
    }
