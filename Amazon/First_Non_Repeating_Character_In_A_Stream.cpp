string FirstNonRepeating(string A){
		    if(A.length()<=1)
		    return A;
		    // Code here
		    int check[26];
		    queue<char>q;
		    memset(check,0,sizeof(check));
		    string ans="";
		    for(int i=0;i<A.length();i++){
		        check[A[i]-'a']++;
		        while(!q.empty() && check[q.front()-'a']>1)
		            q.pop();
		        if(check[A[i]-'a']==1)
		        q.push(A[i]);
		        if(q.empty())
		        ans+='#';
		        else
		        ans+=q.front();
		        
		        
		    }
		    return ans;
		}
