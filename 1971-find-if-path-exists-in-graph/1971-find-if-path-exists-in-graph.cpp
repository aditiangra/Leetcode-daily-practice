class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>vis(n,false);
        queue<int>q;
        q.push(start);
        vis[start]=true;
        while(q.empty()==false)
        {
            int top=q.front();
            q.pop();
            if(top==end)return true;
            for(auto it:graph[top])
            {
               if(vis[it]==false)
               {
                   q.push(it);
                   vis[it]=true;
               }
            }
        }
        return false;
    }
};