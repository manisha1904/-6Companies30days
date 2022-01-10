string colName (long long int n)
    {
        // your code here
        string ans="";
        while(n){
            int rem=n%26;
            //cout<<rem<<"  ";
            if(rem==0){
                ans+='Z';
                n=(n/26)-1;
            }
            else{
            ans+=('A'+rem-1);
            n/=26;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
