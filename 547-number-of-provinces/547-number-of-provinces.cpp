class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                dfs(isConnected,visited,i,n);
                count++;
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>&isConnected,vector<bool>&visited,int s,int n)
    {
        visited[s]=true;
        vector<int>adj;
        for(int i=0;i<n;i++)
        {
            int x=isConnected[s][i];
            if(x==1)
            {
                adj.push_back(i);
            }
        }
        for(auto x:adj)
        {
            if(visited[x]==false)
            {
                dfs(isConnected,visited,x,n);
            }
        }
    }
};