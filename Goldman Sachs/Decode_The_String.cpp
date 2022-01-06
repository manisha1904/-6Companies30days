string decodedString(string s){
        // code here
        stack<char>st;
        stack<char>count;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]>'0' && s[i]<='9'){
                int n=s[i]-'0';
                i++;
                while(i<s.length() && s[i]>='0' && s[i]<='9'){
                    n=n*10+(s[i]-'0');
                    i++;
                }
                i--;
                count.push(n);
            }
            else if(s[i]==']'){
                string temp="";
                while(!st.empty() && st.top()!='['){
                    temp=st.top()+temp;
                    st.pop();
                }
                st.pop();
                int c=count.top();
                count.pop();
                string t=temp;
                for(int j=1;j<c;j++){
                    temp+=t;
                }
                for(int j=0;j<temp.size();j++)
                    st.push(temp[j]);
            }
            else
            st.push(s[i]);
        }
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
        
    }
