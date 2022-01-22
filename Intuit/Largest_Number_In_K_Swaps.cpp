string ans="";
    void solve(string str,int idx,int k){
        if(k==0)
        return;
        int n=str.length();
        char ch=str[idx];
        for(int i=idx+1;i<n;i++){
            if(ch<str[i])
            ch=str[i];
        }
        if(ch!=str[idx])
        k--;
        for(int j=n-1;j>=idx;j--){
            if(str[j]==ch){
                swap(str[j],str[idx]);
                if(ans<str)
                ans=str;
                solve(str,idx+1,k);
                swap(str[j],str[idx]);
            }
        }
        
        
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       ans=str;
       solve(str,0,k);
       return ans;
      
    }
