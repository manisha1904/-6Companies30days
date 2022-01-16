class graph{
    public:
    int V;
    list<int>* adj;
    graph(int v){
        this->V=v;
        adj= new list<int>[V];
    }
    void addEdge(int u,int v){
    adj[u].push_back(v);
}
};

class Solution{
    public:
    void dictOrder(string s1,string s2,graph* g,bool* exist){
        int n=s1.length();
        int m=s2.length();
        int i=0;
        for(int i=0;i<n;i++)
        exist[(int)s1[i]]=true;
        for(int j=0;j<m;j++)
        exist[(int)s2[j]]=true;
        while(i<n && i<m){
            if(s1[i]!=s2[i]){
                g->addEdge((int)s1[i],(int)s2[i]);
                return;
            }
            i++;
        }
    }
    
    void topology(int v,list<int>* adj,bool* exist,bool* visited,stack<char>& st){
        if(exist[v]){
            visited[v]=true;
            for(auto x:adj[v]){
                if(!visited[x])
                topology(x,adj,exist,visited,st);
            }
            st.push((char)v);
        }
    }

    string findOrder(string dict[], int N, int K) {
        //code here
        graph* g=new graph(256);
        bool exist[256];
        memset(exist,false,sizeof(exist));
        for(int i=1;i<N;i++){
            dictOrder(dict[i-1],dict[i],g,exist);
        }
        bool visited[256];
        stack<char>st;
        string ans="";
        memset(visited,false,sizeof(visited));
        for(int i=0;i<256;i++){
            if(!visited[i])
            topology(i,g->adj,exist,visited,st);
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
        
        
    }
};
