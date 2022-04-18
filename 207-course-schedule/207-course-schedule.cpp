class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& pre) {
        vector<int> adj[V];
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        vector<int>indegree(V,0);
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
        int cnt=0;
        while(q.empty()==false)
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
            cnt++;
        }
        if(cnt==V)return true;
        return false;
    }
};