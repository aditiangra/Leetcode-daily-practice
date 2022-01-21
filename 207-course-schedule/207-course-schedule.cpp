class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& pre) {
        if(V==0)return true;
          vector<vector<int>> adj(V);
        for(int i=0; i<pre.size(); i++) // convert edge list to adjacency list
            adj[pre[i][1]].push_back(pre[i][0]);
        vector<int>indegree(V,0);
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])indegree[it]++;
        }
        //indegree done//
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        //pushing done//
        int count=0;
        while(q.empty()==false)
        {
            int node=q.front();
            q.pop();
            count++;
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        if(count==V)return true;
        return false;
    }
};