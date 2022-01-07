string printMinNumberForPattern(string S){
        // code here
        if(S=="")
        return "";
        string ans="";
        vector<int>v;
        int min_val=0,pos=0;
        if(S[0]=='D'){
            v.push_back(2);
            v.push_back(1);
            min_val=3;
            pos=0;
        }
        else{
            v.push_back(1);
            v.push_back(2);
            min_val=3;
            pos=1;
        }
        for(int i=1;i<S.length();i++){
            if(S[i]=='I'){
                v.push_back(min_val);
                min_val++;
                pos=i+1;
            }
            else{
                v.push_back(v[i]);
                for(int j=pos;j<=i;j++){
                    v[j]++;
                }
                min_val++;
            }
        }
        for(int i=0;i<v.size();i++){
            ans+=(v[i]+'0');
        }
        return ans;
    }
