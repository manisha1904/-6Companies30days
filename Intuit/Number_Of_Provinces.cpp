int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>graph[isConnected.size()];
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1 && i!=j)
                    graph[i].push_back(j);
            }
        }
        bool visited[isConnected.size()];
        memset(visited,false,sizeof(visited));
        int ans=0;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int u=q.front();
                    visited[u]=true;
                    q.pop();
                    for(auto& x:graph[u]){
                        if(!visited[x])
                            q.push(x);
                    }
                }
                ans++;
            }
        }
        return ans;
        
    }
