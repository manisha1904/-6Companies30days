struct compare{
       bool operator()(string& s2,string& s1){
        if(s1.length()<s2.length())
            return true;
        if(s1.length()>s2.length())
            return false;
        else{
            for(int i=0;i<s1.length();i++){
                if(s1[i]<s2[i])
                    return true;
                if(s1[i]>s2[i])
                    return false;
            }
        }
        return false;
    }
   };
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,compare>pq;
        for(auto x:nums){
            pq.push(x);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
        
    }
