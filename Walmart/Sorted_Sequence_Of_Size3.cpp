vector<int> find3Numbers(vector<int> arr, int N) {
        // Your code here
        vector<int>right_max(N),left_max(N);
        right_max[N-1]=arr[N-1];
        left_max[0]=arr[0];
        for(int i=N-2;i>=0;i--){
            right_max[i]=max(right_max[i+1],arr[i]);
        }
        for(int i=1;i<N;i++){
            left_max[i]=min(left_max[i-1],arr[i]);
        }
        vector<int>ans;
        for(int i=1;i<N-1;i++){
            if(left_max[i-1]<arr[i] && arr[i]<right_max[i+1]){
                ans.push_back(left_max[i-1]);
                ans.push_back(arr[i]);
                ans.push_back(right_max[i+1]);
                break;
            }
        }
        return ans;
    }
