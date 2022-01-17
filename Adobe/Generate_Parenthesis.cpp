void solve(int open,int close,int n,string s,vector<string>&ans){
        if(open==n && close==n){
            ans.push_back(s);
            return;
        }
        if(open<n){
        solve(open+1,close,n,s+'(',ans);
        }
        if(open>close){
        solve(open,close+1,n,s+')',ans);
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string>ans;
        solve(0,0,n,"",ans);
        return ans;
    }
