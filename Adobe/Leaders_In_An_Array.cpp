vector<int> leaders(int a[], int n){
        // Code here
        vector<int>suffix(n);
        vector<int>ans;
        suffix[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],a[i]);
        }
        for(int i=0;i<n;i++){
            if(a[i]==suffix[i])
            ans.push_back(a[i]);
        }
        return ans;
        
    }
