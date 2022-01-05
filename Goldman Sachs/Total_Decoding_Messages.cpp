/*int CountW(string s,int n){
	    if(n==0 || n==1)
	    return 1;
	    if(s[0]=='0')
	    return 0;
	    int count=0;
	    if(s[n-1]!='0')
	    count+=CountW(s,n-1);
	    if(s[n-2]=='1' || (s[n-2]=='2' && s[n-1]<='6'))
	    count+=CountW(s,n-2);
	    return count;
	}*/
		int CountWays(string str){
		    // Code here
		    if(str[0]=='0')
		    return 0;
		    long long mod=1e9+7;
		    long long count[str.length()+1];
		    count[0]=1;
		    count[1]=1;
		    for(int i=2;i<=str.length();i++){
		        count[i]=0;
		        if(str[i-1]>'0')
		        count[i]=count[i-1];
		        if(str[i-2]=='1' || (str[i-2]=='2' && str[i-1]<='6'))
		        count[i]+=count[i-2];
		        count[i]%=mod;
		    }
		    return (int)count[str.length()];
		    
		    
		}
