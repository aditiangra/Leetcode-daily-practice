class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>>graph(n);//adjacency list//
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>visited(n,false);
        queue<int>q1;
        q1.push(start);
        visited[start]=true;
        while(q1.empty()==false)
        {
            int top=q1.front();
            q1.pop();
            if(top==end)return true;
            for(auto it:graph[top])
            {
                if(visited[it]==false)
                {
                    q1.push(it);
                    visited[it]=true;
                }
            }
        }
        return false;
        
    }
};