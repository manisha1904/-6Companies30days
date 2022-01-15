void dfs(int v,bool* visited,vector<int> adj[]){
        visited[v]=true;
        for(auto i=adj[v].begin();i!=adj[v].end();i++){
            if(!visited[*i])
            dfs(*i,visited,adj);
        }
        
    }
    
    bool isConnected(int V,vector<int>adj[],int c,int d){
        bool visited[V];
       memset(visited,false,sizeof(visited));
       dfs(c,visited,adj);
       if(visited[d]==false)
       return 0;
       return 1;
        
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
       if(!isConnected(V,adj,c,d))
       return 0;
       
       adj[c].erase(remove(adj[c].begin(),adj[c].end(),d),adj[c].end());
       adj[d].erase(remove(adj[d].begin(),adj[d].end(),c),adj[d].end());
       
       if(isConnected(V,adj,c,d))
       return 0;
       
        return 1;
        
    }
