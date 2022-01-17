int atoi(string str) {
        //Your code here
        int ans=0;
        int j=(str[0]!='-'?0:1);
        for(int i=j;i<str.length();i++){
            if(str[i]<'0' || str[i]>'9')
            return -1;
            ans=ans*10+(str[i]-'0');
        }
        if(j==1)
        ans= ans*(-1);
        return ans;
    }
