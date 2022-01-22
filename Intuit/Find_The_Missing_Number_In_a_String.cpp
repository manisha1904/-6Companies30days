int convertToInteger(const string& s,int i,int n){
    if(i+n>s.length())
    return -1;
    int ans=0;
    for(int j=0;j<n;j++){
        int temp=s[i+j]-'0';
        if(temp<0 || temp>9)
        return -1;
        ans=ans*10+temp;
    }
    return ans;
}

int missingNumber(const string& str)
{
    // Code here
    bool fail=false;
    int missed=-1;
    for(int len=1;len<=6;len++){
        int first=convertToInteger(str,0,len);
        //cout<<first<<"  ";
        if(first==-1)
        break;
         fail=false;
         missed=-1;
        for(int i=len;i!=str.length();i+=1+log10l(first)){
            if((missed==-1) && (convertToInteger(str,i,1+log10l(first+2)))==first+2){
                missed=first+1;
                first+=2;
            }
            else if((convertToInteger(str,i,1+log10l(first+1)))==first+1)
            first++;
            else
            {
                fail=true;
                break;
            }
        }
        if(!fail)
        return missed;
    }
    
    return -1;
}
