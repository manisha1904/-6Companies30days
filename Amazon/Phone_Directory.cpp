class TrieNode{
    public:
    TrieNode* children[26];
    bool isEndNode;
};

TrieNode* getNode(){
    TrieNode* root= new TrieNode;
    root->isEndNode=false;
    for(int i=0;i<26;i++)
        root->children[i]=NULL;
        
    return root;
}

void insert(TrieNode* root,string key){
    TrieNode* temp=root;
    for(int i=0;i<key.length();i++){
        int index=key[i]-'a';
        if(!temp->children[index])
            temp->children[index]=getNode();
        temp=temp->children[index];
        if(i==key.length()-1)
        temp->isEndNode=true;
    }
}

void allBranches(TrieNode* root,string prefix,vector<string>&v){
    if(root->isEndNode)
    {
        v.push_back(prefix);
    
    }
    
    for(char ch='a';ch<='z';ch++){
        TrieNode* nextNode=root->children[ch-'a'];
        if(nextNode)
        allBranches(nextNode,prefix+ch,v);
    }
}
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        TrieNode* root=getNode();
        //for(int i=0;i<n;i++)
        //root[i]=getNode();
        for(int i=0;i<n;i++){
            //root[i]=getNode();
            insert(root,contact[i]);
        }
        vector<vector<string>>ans;
        string temp="";
        int i=0;
        for(i=0;i<s.length();i++){
            temp+=s[i];
            vector<string>v;
            TrieNode* curr=root->children[temp[i]-'a'];
            if(!curr){
                v.push_back("0");
                ans.push_back(v);
                break;
            }
            allBranches(curr,temp,v);
            root=curr;
            ans.push_back(v);
        }
        for(;i<s.length();i++){
            vector<string>v;
            v.push_back("0");
            ans.push_back(v);
        }
        return ans;
    }
