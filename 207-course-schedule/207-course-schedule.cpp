class Solution {
public:
    bool canFinish(int V, vector<vector<int>>&pre) {
        vector<int> adj[V];
        for(auto it:pre)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indegree(V);
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        int cntr=0;
        while(q.empty()==false)
        {
            int u=q.front();
            q.pop();
            for(auto it:adj[u])
            {
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
            cntr++;
        }
        if(cntr==V)return true;
      
            return false;
    }
};