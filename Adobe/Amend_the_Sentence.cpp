string amendSentence (string s)
    {
        // your code here
        char ch=tolower(s[0]);
        s[0]=ch;
        string ans="";
        ans+=ch;
        for(int i=1;i<s.length();i++){
            if(s[i]>='A' && s[i]<='Z'){
                ans+=" ";
                ans+=tolower(s[i]);
            }
            else
            ans+=s[i];
        }
        return ans;
    }
