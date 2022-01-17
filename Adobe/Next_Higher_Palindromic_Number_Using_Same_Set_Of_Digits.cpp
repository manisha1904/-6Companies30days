string nextPalin(string N) { 
        //complete the function here
        int len=N.length()/2;
        string temp=N.substr(0,len);
        int idx=-1;
        for(int i=len-1;i>0;i--){
            if(temp[i]>temp[i-1]){
                idx=i-1;
                break;
            }
        }
        int end=-1;
        if(idx==-1)
        return "-1";
        for(int i=len-1;i>idx;i--){
            if(temp[idx]<temp[i]){
                end=i;
                break;
            }
        }
        char t=temp[idx];
        temp[idx]=temp[end];
        temp[end]=t;
        
        reverse(temp.begin()+idx+1,temp.end());
        
        string rev=temp;
        reverse(rev.begin(),rev.end());
        if(N.length()%2!=0)
        temp+=N[N.length()/2];
        temp+=rev;
        
        return temp;
    }
