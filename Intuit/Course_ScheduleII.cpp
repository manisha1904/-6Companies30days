vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>v[numCourses];
        vector<int>ans;
        vector<int>indegree(numCourses,0);
        for(auto& edge:prerequisites){
            v[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(!indegree[i])
                q.push(i);
        }
        if(q.empty())
            return ans;
        int count=0;
        while(!q.empty()){
            int u=q.front();
            ans.push_back(u);
            q.pop();
            for(auto& x:v[u]){
                indegree[x]--;
                if(indegree[x]==0)
                    q.push(x);
            }
            count++;
        }
        if(count!=numCourses)
            return {};
        return ans;
        
        
    }
