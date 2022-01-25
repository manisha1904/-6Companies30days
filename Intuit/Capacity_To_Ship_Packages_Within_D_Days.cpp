int shipWithinDays(vector<int>& weights, int days) {
        int start=0;
        int end=0;
        for(int i=0;i<weights.size();i++){
            start=max(start,weights[i]);
            end+=weights[i];
        }
        while(start<=end){
            int mid=(start+end)/2;
            int d=days;
            int i=0;
            while(d){
                int temp=0;
                while(i<weights.size()){
                    temp+=weights[i];
                    if(temp>mid)
                        break;
                    i++;
                }
                d--;
            }
            if(i==weights.size())
                end=mid-1;
            else
                start=mid+1;
        }
        return start;
        
    }
