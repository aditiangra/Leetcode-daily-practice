class Solution {
public:
    void dfs(int v,vector<bool>& visited,vector<vector<int>>& graph)
    {
        //marking the node as visited//
        visited[v]=true;
        //checking for neighbours//
        for(int i=0;i<graph[v].size();i++)
        {
            if(i==v)continue;
            if(graph[v][i]==1 and visited[i]==false)
            {
                dfs(i,visited,graph);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& graph) {
        int n=graph.size();
        //making the visited array//
        vector<bool> visited(n,false);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                cnt++;
                dfs(i,visited,graph);
            }
        }
        return cnt;
    }
};