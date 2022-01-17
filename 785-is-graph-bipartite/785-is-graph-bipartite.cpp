class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
      int n=graph.size();
        vector<int>color(n,-1);
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(color[i]=-1)
            {
                if(check(i,graph,color)==false)return false;
            }
        }
        return true;
    }
    bool check(int src,vector<vector<int>>& graph,vector<int>color)
    {
        queue<int>q;
        q.push(src);
        color[src]=1;
        while(q.empty()==false)
        {
            int node=q.front();
            q.pop();
            for(auto it:graph[node])
            {
                if(color[it]==-1)
                {
                    color[it]=1-color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
};