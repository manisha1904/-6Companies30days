vector<string>ans;
    //Function to find list of all words possible by pressing given numbers.
    unordered_map<int,vector<char>>m;
    void solve(int arr[],int i,int n,string s){
        if(i==n){
            ans.push_back(s);
            return;
        }
        for(auto x:m[arr[i]]){
            solve(arr,i+1,n,s+x);
        }
    }
    vector<string> possibleWords(int arr[], int N)
    {
        //Your code here
        m[2].push_back('a');
        m[2].push_back('b');
        m[2].push_back('c');
        m[3].push_back('d');
        m[3].push_back('e');
        m[3].push_back('f');
        m[4].push_back('g');
        m[4].push_back('h');
        m[4].push_back('i');
        m[5].push_back('j');
        m[5].push_back('k');
        m[5].push_back('l');
        m[6].push_back('m');
        m[6].push_back('n');
        m[6].push_back('o');
        m[7].push_back('p');
        m[7].push_back('q');
        m[7].push_back('r');
        m[7].push_back('s');
        m[8].push_back('t');
        m[8].push_back('u');
        m[8].push_back('v');
        m[9].push_back('w');
        m[9].push_back('x');
        m[9].push_back('y');
        m[9].push_back('z');
        solve(arr,0,N,"");
        return ans;
    }
