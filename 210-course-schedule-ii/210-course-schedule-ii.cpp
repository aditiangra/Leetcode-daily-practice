class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>indegree(n,0);
        queue<int>q;
      vector<int>adj[n];
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
               indegree[it]++;
            }
        }
        //indegree done//
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        //queue pushing done//
        vector<int>topo;
        vector<int>res;
        int cnt=0;
        while(q.empty()==false)
        {
            int node=q.front();
            q.pop();
            cnt++;
            topo.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        if(cnt==n)
        return topo;
        else
            return res;
    }
};