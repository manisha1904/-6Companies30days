vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        vector<int>ans;
        int temp=0,start=0;
        for(int i=0;i<n;i++){
            temp+=arr[i];
            if(temp>=s){
                while(temp>s && start<i){
                    temp-=arr[start];
                    start++;
                }
                if(temp==s){
                    ans.push_back(start+1);
                    ans.push_back(i+1);
                    return ans;
                }
            }
        }
        ans.push_back(-1);
        return ans;
    }
