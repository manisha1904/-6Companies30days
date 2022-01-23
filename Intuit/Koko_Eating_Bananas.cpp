int minEatingSpeed(vector<int>& piles, int h) {
        long long int max_value=LLONG_MIN;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]>max_value)
                max_value=piles[i];
        }
        long long int min_value=1;
        long long int ans=LLONG_MAX;
        while(min_value<=max_value){
            long long int mid=(max_value+min_value)/2;
            long long int count=0;
            for(int i=0;i<piles.size();i++){
                if(piles[i]%mid==0)
                    count+=(piles[i]/mid);
                else
                count=count+(piles[i]/mid)+1;
            }
            cout<<min_value<<"  "<<max_value<<endl;
            if(count<=h){
                ans=min(mid,ans);
                max_value=mid-1;
                
            }
            
            else
                min_value=mid+1;
        }
        return ans;
        
    }
