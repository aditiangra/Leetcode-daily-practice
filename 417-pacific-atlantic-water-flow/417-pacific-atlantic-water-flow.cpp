class Solution {
public:
    int m,n;
    vector<vector<bool>>atlantic,pacific;
    vector<vector<int>>ans;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size();
        n=heights[0].size();
        if(m==0)return ans;
        atlantic=pacific=vector<vector<bool>>(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            dfs(heights,pacific,i,0),dfs(heights,atlantic,i,n-1);
        }
        for(int j=0;j<n;j++)
        {
            dfs(heights,pacific,0,j),dfs(heights,atlantic,m-1,j);
        }
        return ans;
    }
    void dfs(vector<vector<int>>& heights,vector<vector<bool>>& visited,int i,int j)
    {
        if(visited[i][j]==true)return;
        visited[i][j]=true;
        if(atlantic[i][j]  &&pacific[i][j])
        {
            ans.push_back({i,j});
        }
        if(i-1>=0 and heights[i-1][j]>=heights[i][j])dfs(heights,visited,i-1,j);
        if(i+1<m and heights[i+1][j]>=heights[i][j])dfs(heights,visited,i+1,j);
        if(j-1>=0 and heights[i][j-1]>=heights[i][j])dfs(heights,visited,i,j-1);
        if(j+1<n and heights[i][j+1]>=heights[i][j])dfs(heights,visited,i,j+1);
    }
};