unordered_map<int,vector<int>>graph;
bool cycleUtil(int v,bool* recStack,bool* visited ){
    if(visited[v]==false){
        visited[v]=true;
        recStack[v]=true;
        for(auto i=graph[v].begin();i!=graph[v].end();i++){
            if(!recStack[*i] && cycleUtil(*i,recStack,visited))
            return true;
            if(recStack[*i])
            return true;
        }
    }
    recStack[v]=false;
    return false;
    
}

bool cycle(int n){
    bool recStack[n],visited[n];
    memset(recStack,false,sizeof(recStack));
    memset(visited,false,sizeof(visited));
    for(int i=0;i<n;i++){
        if(cycleUtil(i,recStack,visited))
        return true;
    }
    return false;
}
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code here
	    for(int i=0;i<pre.size();i++){
	        graph[pre[i].second].push_back(pre[i].first);
	    }
	    if(cycle(N+1))
	    return false;
	    return true;
	    
	    
	}
