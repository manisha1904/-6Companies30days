vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string,int>m;
        for(int i=0;i<n;i++)
        m[arr[i]]++;
        vector<string>ans;
        int count=0;
        string name;
        for(auto x:m){
            if(count<x.second)
            {
                name=x.first;
                count=x.second;
            }
            else if(count==x.second && name>x.first){
                name=x.first;
            }
            
        }
        ans.push_back(name);
        ans.push_back(to_string(count));
        return ans;
    }
